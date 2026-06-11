#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
    int n; cin >> n;
    long long su = 0;
    while(n--) {
        int i; cin >> i;
        v.push_back(i);
        su += i;
    }
    long long csu = 0, ans = 0xFFFFFFFFFFFFFFull;
    for(int i:v) {
        csu += i;
        ans = min(ans, max(2*csu - su, su-2*csu));
    }
    cout << ans << endl;
} 
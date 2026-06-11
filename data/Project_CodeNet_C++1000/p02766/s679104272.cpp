#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, k, cnt = 0;
    ;
    cin >> n >> k;
    vector<int> a;
    while(n) {
        a.push_back(n % k);
        n /= k;
        cnt++;
    }
    reverse(a.begin(), a.end());
    cout << cnt << endl;
    return 0;
}
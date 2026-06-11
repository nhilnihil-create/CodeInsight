#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long


int main() {
    int n; cin >>n;
    int k; cin >> k; int ans;
    if (k==1) {
        ans = 0;
    }
    else {
        ans = n - k;
    }
    cout << ans << endl;
}

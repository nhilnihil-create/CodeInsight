#include<bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
    int n, x;
    cin >> n >> x;
    int a, ans = 0;
    for(int i=0; i<n; ++i){
        cin >> a;
        if(a>=x)
            ans++;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}

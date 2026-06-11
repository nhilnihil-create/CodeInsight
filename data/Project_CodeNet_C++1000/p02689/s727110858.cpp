#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> h(n+1), ma(n+1);
    for(int i=1; i<=n; i++){
        cin >>h[i];
        ma[i] = 0;
    }
    rep(i, m){
        int a, b;
        cin >> a >> b;
        ma[a] = max(ma[a], h[b]);
        ma[b] = max(ma[b], h[a]);

    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        ans += h[i]>ma[i];
    }
    cout << ans << endl;
    return 0;
}
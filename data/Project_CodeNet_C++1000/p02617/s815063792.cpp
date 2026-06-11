#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    if (fopen("input.in", "r")) {
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    }
    int n;
    cin>>n;
    ll ans = 0;
    for(int i = 1; i<= n; i++) ans += ((ll)i) * ((ll)n - i + 1);
    for(int i = 0; i< n-1; i++){
        int u, v;
        cin>>u>>v;
        if(u> v) swap(u,v);
        ans -= (ll)u * (n-v+1);
    }
    cout<<ans<<"\n";
}

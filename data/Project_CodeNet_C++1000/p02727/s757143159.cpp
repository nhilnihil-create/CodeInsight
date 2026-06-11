#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //good luck kittu!
    int x, y, A, B, C;
    cin>>x>>y>>A>>B>>C;
    vector<ll> a(A), b(B), c(C);
    for(int i = 0; i<A; i++) cin>>a[i];
    for(int i = 0; i<B; i++) cin>>b[i];
    for(int i = 0; i<C; i++) cin>>c[i];

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    
    for(int i = 0; i<x; i++) c.push_back(a[i]);
    for(int i = 0; i<y; i++) c.push_back(b[i]);

    sort(c.rbegin(), c.rend());
    ll ans = 0;
    for(int i = 0; i<x+y; i++) ans += c[i];
    cout<<ans<<"\n";
    return 0;
}
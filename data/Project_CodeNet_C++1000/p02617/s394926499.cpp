#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin>>N;
    ll ans=N*(N+1)*(N+2)/6;
    for (int i = 0; i < N-1; i++){
        int u,v;
        cin>>u>>v;
        ll m=min(u,v);
        ll M=max(u,v);
        ans-=m*(N-M+1);
    }
    cout<<ans<<endl;
}
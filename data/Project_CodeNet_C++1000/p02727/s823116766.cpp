#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int X,Y,A,B,C;
    cin>>X>>Y>>A>>B>>C;
    vector<ll> p(A);
    vector<ll> q(B);
    vector<ll> r(C);

    for(int i=0; i<A; i++) cin>>p[i];
    for(int i=0; i<B; i++) cin>>q[i];
    for(int i=0; i<C; i++) cin>>r[i];

    vector<ll> al;

    sort(p.begin(),p.end(),greater<ll>());
    sort(q.begin(),q.end(),greater<ll>());

    for(int i=0; i<X; i++) al.push_back(p[i]);
    for(int i=0; i<Y; i++) al.push_back(q[i]);
    for(int i=0; i<C; i++) al.push_back(r[i]);

    sort(al.begin(),al.end(),greater<ll>());

    ll ans = accumulate(al.begin(),al.begin()+X+Y,0ll);

    cout<<ans<<endl;

    return 0;

}
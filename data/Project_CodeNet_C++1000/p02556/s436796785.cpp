#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define rep(i,s,e) for(int i=s;i<e;i++)
#define endl '\n'
ll dist(ll x1,ll x2,ll y1,ll y2){
    return abs(x2-x1)+abs(y2-y1);
}
int main(){
    int N;cin>>N;
    vector<ll> X(N),Y(N),P(N),Q(N);
    rep(i,0,N)cin>>X[i]>>Y[i];
    rep(i,0,N){
        P[i]=X[i]-Y[i];
        Q[i]=X[i]+Y[i];
    }
    sort(P.begin(),P.end());
    sort(Q.begin(),Q.end());
    ll ans=max(abs(P.back()-P.front()),abs(Q.back()-Q.front()));
    cout<<ans<<endl;
}
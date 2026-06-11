#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

ll d[5005]={};
ll dm[5005]={};

ll solve(ll n, ll x, ll m, ll k){
    ll begin=x;
    REP(i,5005)dm[i]=d[i]%m;
    ll syu = 0;
    REP(i,k)syu+=dm[i];
    ll end=syu*((n-1)/k)+begin;
    REP(i,(n-1)%k)end+=dm[i];
    ll down = end/m - begin/m;

    ll samsyu=0;
    REP(i,k){
        if(dm[i]==0)samsyu++;
    }
    ll same = samsyu*((n-1)/k);
    REP(i,((n-1)%k))if(dm[i]==0)same++;

    return n-1-same-down;
}

int main(){
    ll k,q,dd;
    cin>>k>>q;
    ll n,x,m;
    REP(i,k){
        cin>>dd;
        d[i]=dd;
    }
    REP(i,q){
        cin>>n>>x>>m;
        cout<<solve(n,x,m,k)<<endl;
    }
}
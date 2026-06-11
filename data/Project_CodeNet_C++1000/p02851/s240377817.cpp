#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
    int N,K;cin>>N>>K;
    vector<ll> A(N);
    REP(i,N) cin>>A[i],A[i]--;
    map<ll,int> mp;
    ll s=0,sl=0,ans=0;
    REP(i,min(K-1,N)){
        mp[s]++;
        s+=A[i];
        s%=K;
        ans+=mp[s];
    }
    rep(i,K-1,N){
        mp[sl]--;
        mp[s]++;
        s+=A[i];
        s%=K;
        sl+=A[i-K+1];
        sl%=K;

        ans+=mp[s];
    }
    cout<<ans<<endl;
}

#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,N-1,0)
#define RREPS(i,n) RFOR(i,N,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
const int INF=1e18;
const int MOD=1e9+7;

signed main(){
    string S;cin>>S;
    int N=S.size();
    if(N==1)cout<<1;
    if(N==2)cout<<(S[0]==S[1]?1:2);
    if(N>=3){
    int d[N];
    REP(i,N)d[i]=0;
    d[0]=1;
    d[1]=(S[0]==S[1]?1:2);
    d[2]=(S[1]==S[2]?2:d[1]+1);
    for(int i=3;i<N;i++){
        if(S[i]==S[i-1]){
            d[i]=d[i-3]+2;
        }
        else d[i]=d[i-1]+1;
    }
    cout<<d[N-1]<<endl;
    }
}
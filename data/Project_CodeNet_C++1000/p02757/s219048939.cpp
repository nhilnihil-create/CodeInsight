#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,0,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int INF=1e18;
int N,P;
int powMOD(int x,int r,int MOD){
    if(r==0)return 1;
    if(r%2==0)return powMOD(x,r/2,MOD)*powMOD(x,r/2,MOD)%MOD;
    else return powMOD(x,r-1,MOD)*x%MOD;
}

signed main(){
    string S;cin>>N>>P>>S;
    int ans=0;
    reverse(S.begin(),S.end());
    if(P!=2&&P!=5){
        int R[N];
        REP(i,N){
            int d=(int)S[i]-'0';
            if(i==0)R[0]=d%P;
            else R[i]=(R[i-1]+d*powMOD(10,i,P))%P;
        }
        map<int,int>memo;
        REP(i,N)memo[R[i]]++;
      	memo[0]++;
        for(auto v:memo){
            ans+=v.second*(v.second-1)/2;
        }
    }
    else{
        REP(i,N){
            int d=S[i]-'0';
            if(d%P==0)ans+=N-i;
        }
    }
    cout<<ans<<endl;
}
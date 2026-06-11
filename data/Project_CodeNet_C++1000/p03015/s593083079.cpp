#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
const int MOD=1e9+7;
const int INF=1e15;

signed main(){
    string S;cin>>S;
    int N=S.size();
    int dpk[N+1];//L未満が確定
    int dpm[N+1];//L未満か未確定
    REPS(i,N){
        int d=S[i-1]-'0';
        if(i==1){
            dpk[i]=1;
            dpm[i]=2;
        }
        else{
            if(d==0){
                dpk[i]=(dpk[i-1]*3)%MOD;
                dpm[i]=dpm[i-1];
            }
            if(d==1){
                dpk[i]=(dpk[i-1]*3+dpm[i-1])%MOD;
                dpm[i]=(dpm[i-1]*2)%MOD;
            }
        }
    }
    cout<<(dpk[N]+dpm[N])%MOD<<endl;
}
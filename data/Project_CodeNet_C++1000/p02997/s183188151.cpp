#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define zero_pad(num) setfill('0') << std::right << setw(num)
const int MOD=1e9+7;
const int INF=1e18;



signed main(){
    int N,K;cin>>N>>K;
    if(K>(N-1)*(N-2)/2)cout<<-1<<endl;
    else{
        vector<pair<int,int>>A;
        REP(i,N-1)A.pb({1,i+2});
        bool isused[N-1][N-1];
        REP(i,N-1)REP(j,N-1)isused[i][j]=false;
        REP(k,(N-1)*(N-2)/2-K){
            for(int i=2;i<N;i++){
                bool ok=false;
                for(int j=i+1;j<=N;j++){
                    if(!isused[i-2][j-2]){
                        A.pb({i,j});
                        isused[i-2][j-2]=true;
                        ok=true;
                        break;
                    }
                }
                if(ok)break;
            }
        }
        cout<<A.size()<<endl;
        REP(i,A.size()){
            cout<<A[i].first<<" "<<A[i].second<<endl;
        }
    }
}
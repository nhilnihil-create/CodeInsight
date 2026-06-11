#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
const int MOD=1e9+7;
const int INF=1e15;

signed main(){
    int N;cin>>N;
    vector<int>A(N,0);
    REP(i,N)cin>>A[i];
    bool okz=true;
    REP(i,N){
        if(A[i]!=0)okz=false;
    }
    bool oko=false;
    sort(A.begin(),A.end());
    if(N%3==0){
        if(A[0]==A[N/3-1]&&A[N/3]==0&&A[N-1]==0)oko=true;
    }
    bool okt=false;
    if(N%3==0){
        if((A[0]^A[N/3]^A[N*2/3])==0&&A[0]==A[N/3-1]&&A[N/3]==A[N*2/3-1]&&A[N*2/3]==A[N-1]){
            okt=true;
        }
    }
    if(oko||okt||okz)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
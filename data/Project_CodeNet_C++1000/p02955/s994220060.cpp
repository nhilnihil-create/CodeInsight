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
    int A[N];
    int sum=0;
    REP(i,N){
        cin>>A[i];
        sum+=A[i];
    }
    int C=sum;
    map<int,int>memo;
    for(int i=1;i<=sqrt(sum);i++){
        if(C%i==0){
            memo[i]++;
            memo[C/i]++;
        }
    }
    int ans=1;
    for(auto v:memo){
        int d=v.first;
        vector<int>B;
        REP(i,N){
            if(A[i]%d!=0)B.pb(A[i]%d);
        }
      	int W=B.size();
      	if(W==0){
          	ans=max(ans,d);
          	continue;
        }
        sort(B.begin(),B.end());
        int lb[W],rb[W];
        REP(i,W){
            if(i==0)lb[0]=B[0];
            else lb[i]=lb[i-1]+B[i];
        }
        REP(i,W){
            if(i==0)rb[W-1]=d-B[W-1];
            else rb[W-1-i]=rb[W-i]+d-B[W-1-i];
        }
        REP(i,W){
            if(abs(lb[i]-rb[i+1])%d==0&&max(lb[i],rb[i+1])<=K)ans=max(ans,d);
        }
    }
    cout<<ans<<endl;
}
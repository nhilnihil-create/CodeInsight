#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fo(i,s,e) for( i=s;i<e;i++)
#define rfo(i,s,e) for(i=s;i>e;i--)
#define LL long long int 
const LL MOD=1e9+7;
#define pb push_back
#define pob pop_back()
#define sp " "
#define ff first
#define ss second
//            When something is important enough, you do it even if the odds are not in your favor.

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // code goes here
    int t=1;//cin>>t;
    while(t--){
      LL n,m,i;cin>>n>>m;
      set<LL> s;
      fo(i,0,m){
        LL x;cin>>x;
        s.insert(x);
      }
      LL dp[n+4];
      dp[n]=1;
      rfo(i,n-1,-1){
        if(s.count(i)) dp[i]=0;
        else{
          dp[i]=dp[i+1];
          if(i!=n-1) dp[i]+=dp[i+2],dp[i]%=MOD;
        }
      }
      cout<<dp[0];
    }
    return 0;
}
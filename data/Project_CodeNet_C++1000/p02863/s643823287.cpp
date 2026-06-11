#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD=1000000007;
const long double PI=3.1415926535;
const ll MAX=1000000;

ll DP[3005][6005];

int main() {
  ll N,T;
  cin>>N>>T;
  pair<ll,ll> food[N];
  //ll time[N];
  ll tMax=0;
  rep(i,N){
    cin>>food[i].first>>food[i].second;
    tMax=max(tMax,food[i].first);
  }
  sort(food,food+N);
  for(int i=0;i<=N;i++){
    for(int j=0;j<=T+tMax;j++){
      if(i*j==0){
        DP[i][j]=0;
        continue;
      }
      if(j-food[i-1].first>=T){
        DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
      }
      else if(j-food[i-1].first>=0){
        DP[i][j]=max(DP[i-1][j],DP[i-1][j-food[i-1].first]+food[i-1].second);
      }
      else{
        DP[i][j]=DP[i-1][j];
      }
    }
  }
  cout<<DP[N][T+tMax];
 // cout<<" "<<DP[2][200];
    
    
}
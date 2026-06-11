#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);++i)
#define fi first
#define se second
#define INF 1000000009
#define lINF 1000000000000000009
typedef long long ll;

int n,k;
int h[309];
ll memo[309][309][309];

ll dp(int i,int cnt,int idx){
  if(memo[i][cnt][idx]!=-1)return memo[i][cnt][idx];
  if(i==n)return 0;
  ll d=(h[i]>h[idx]?h[i]-h[idx]:0);
  ll rec=dp(i+1,cnt,i)+d;
  if(cnt<k){
    rec=min(rec,dp(i+1,cnt+1,idx));
  }
  return memo[i][cnt][idx]=rec;
}

int main(){
  memset(memo,-1,sizeof(memo));
  cin>>n>>k;
  rep(i,n){
    cin>>h[i];
  }

  cout<<dp(0,0,n)<<endl;

  return(0);
}

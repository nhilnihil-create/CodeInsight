#include<bits/stdc++.h>
using namespace std;
int main(void){
  int i,n,k;cin>>n>>k;
  vector<int> p(n),c(n);
  for(i=0; i<n; ++i) cin>>p[i];
  for(i=0; i<n; ++i) cin>>c[i];
  vector<vector<long int>> dp(n, vector<long int>(0));
  for(i=0; i<n; ++i){
    int cnt=0;
    vector<bool> seen(n,false);
    for(int j=i; seen[j]==false;){
      seen[j] = true;
      j = p[j]-1;
      dp[i].push_back(c[j]);
      if(cnt>0) dp[i][cnt] += dp[i][cnt-1];
      ++cnt;
    }
  }
  long int score=0,sum=0,j=0;
  int l,q;
  for(i=0; i<n; ++i){
    l=dp[i].size();
    if(l>=k||dp[i][l-1]<=0){
      q=(k>l? l:k);
      for(l=0; l<q; ++l) if(l==0 || j<dp[i][l]) j=dp[i][l];
    }
    else{
      q=k;
      j=dp[i][l-1]*((q-1)/l);
      q-=((q-1)/l)*l;
      for(int p=0; p<q; ++p) if(p==0 || sum<dp[i][p%l]) sum=dp[i][p%l];
      j+=sum;
    }
    if(score<j || i==0) score=j;
  }
  cout<<score<<endl;
  return 0;
}
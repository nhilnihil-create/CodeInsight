#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}

int main() {
  int H,W;
  cin>>H>>W;
  vector<string>s(H);
  for(int i=0;i<H;i++){
    cin>>s[i];
  }
  vector<vector<int>>sum(H,vector<int>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(s[i][j]=='.'){
        int start=j;
        int cnt=0;
        while(j<W&&s[i][j]=='.'){
          cnt++;
          j++;
        }
        for(int k=start;k<j;k++){
          sum[i][k]+=cnt;
        }
      }
    }
  }
  for(int j=0;j<W;j++){
    for(int i=0;i<H;i++){
      if(s[i][j]=='.'){
        int start=i;
        int cnt=0;
        while(i<H&&s[i][j]=='.'){
          cnt++;
          i++;
        }
        for(int k=start;k<i;k++){
          sum[k][j]+=cnt;
        }
      }
    }
  }
  int ans=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      chmax(ans,sum[i][j]-1);
    }
  }
  cout<<ans<<endl;
  return 0;
}
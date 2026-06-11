#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
typedef pair<ll,ll> P;

int main() {
  int n,m;
  cin>>n>>m;
  vector<vector<char>> s(n, vector<char>(m));
  rep(i,n){
    rep(j,m){
      cin>>s[i][j];
    }
  }
  vector<vector<int>> d(n, vector<int>(m)); 
  if(s[0][0]=='#'){
    d[0][0]++;
  }
  rep2(i,1,n){
    if(s[i][0]!=s[i-1][0]){
      d[i][0]=d[i-1][0]+1;
    }
    else{
      d[i][0]=d[i-1][0];
    }
  }
  rep2(j,1,m){
    if(s[0][j]!=s[0][j-1]){
      d[0][j]=d[0][j-1]+1;
    }
    else{
      d[0][j]=d[0][j-1];
    }
  }
  rep2(i,1,n){
    rep2(j,1,m){
      if(s[i-1][j]==s[i][j-1]){
        if(s[i][j]==s[i-1][j]){
          d[i][j]=min(d[i][j-1],d[i-1][j]);
        }
        else{
          d[i][j]=min(d[i-1][j],d[i][j-1])+1;
        }
      }
      else{
        if(s[i][j]==s[i-1][j]){
          int now=d[i][j-1]+1;
          d[i][j]=min(d[i-1][j],now);
        }
        else{
          int now=d[i-1][j]+1;
          d[i][j]=min(d[i][j-1],now);
        }
      }
    }
  }
  cout<<(d[n-1][m-1]+1)/2<<endl;
}      
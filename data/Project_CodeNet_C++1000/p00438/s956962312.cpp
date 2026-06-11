#include <iostream>
#include <utility>
#include <cstring>
using namespace std;
int a,b,n;
pair<int,int> p[40];
int dp[18][18];
int f(int x,int y){
  if(dp[x][y]) return dp[x][y];
  if(x==a&&y==b){
    dp[x][y]=1;return 1;
  }
  else if(x>a||y>b) return 0;
  for(int i=0;i<n;++i) if(x==p[i].first&&y==p[i].second) return 0;
  dp[x][y]=f(x+1,y)+f(x,y+1);return dp[x][y];
}

int main(){
  int x,y,A;
  while(cin>>a>>b,a||b){
    cin>>n;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;++i){
      cin>>x>>y;
      pair<int,int> q(x,y);
      p[i]=q;
    }
    A=f(1,1);
    cout<<A<<endl;
  }
  return 0;
}
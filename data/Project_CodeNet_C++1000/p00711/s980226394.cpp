#include<functional>
#include<algorithm>
#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define all(v) (v).begin(),(v).end()
#define pf push_front
#define pb push_back
#define int long long
using namespace std;
const int INF=1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int w,h,sx,sy,sum;
char mp[21][21];

int dfs(int y,int x){
  if(0<=y&&y<h&&0<=x&&x<w&&(mp[y][x]=='.'||mp[y][x]=='@')){
    mp[y][x]='$';
    sum++;
    rep(i,4){
      dfs(y+dy[i],x+dx[i]);
    }
  }
  return sum;
}

signed main(){
 
  while(cin>>w>>h,w){
    rep(i,h)rep(j,w){
      cin>>mp[i][j];
      if(mp[i][j]=='@'){
        sy=i;sx=j;
      }
    }
    sum=0;
    cout<<dfs(sy,sx)<<endl;
  }
  return 0;
}
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<cmath>
#define INF 2147483647
#define llINF 9223372036854775807
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long

using namespace std;
int MAP[100][100]={};
int a,b;
int ans=0;
void dfs(int x,int y){
  if(x==a&&y==b){
    ans++;
    return;
  }
  if(x+1>0&&x+1<=a&&!MAP[x+1][y])
    dfs(x+1,y);
  if(y+1>0&&y+1<=b&&!MAP[x][y+1])
    dfs(x,y+1);
}
int main(){
  while(cin>>a>>b,a+b){
    int n;
    for(int i=0;i<100;i++)
      for(int j=0;j<100;j++)
	MAP[i][j]=0;
    ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
      int x,y;
      cin>>x>>y;
      MAP[x][y]=1;
    }
    dfs(1,1);
    cout<<ans<<endl;
  }
  return 0;
}
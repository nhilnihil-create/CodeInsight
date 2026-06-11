#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,pair<int,int>> P;
int main(){
  int H,W;
  cin>>H>>W;
  string s[100];
  int cost[100][100];
  for(int i=0;i<H;i++){
    cin>>s[i];
    for(int j=0;j<W;j++) cost[i][j]=999999;
  }
  priority_queue<P,vector<P>,greater<P>> que;
  que.push(make_pair(0,make_pair(0,0)));
  cost[0][0]=0;
  while(!que.empty()){
    int y=que.top().second.first;
    int x=que.top().second.second;
    que.pop();
    if(y!=H-1&&cost[y+1][x]==999999){
      if(s[y][x]!=s[y+1][x]) cost[y+1][x]=cost[y][x]+1;
      else cost[y+1][x]=cost[y][x];
      que.push(make_pair(cost[y+1][x],make_pair(y+1,x)));
    }
    if(x!=W-1&&cost[y][x+1]==999999){
      if(s[y][x]!=s[y][x+1]) cost[y][x+1]=cost[y][x]+1;
      else cost[y][x+1]=cost[y][x];
      que.push(make_pair(cost[y][x+1],make_pair(y,x+1)));
    }
  }
  if(s[0][0]=='#'&&s[H-1][W-1]=='#') cout<<cost[H-1][W-1]/2+1<<endl;
  else cout<<(cost[H-1][W-1]+1)/2<<endl;
  
  return 0;
}
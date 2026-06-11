#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<stdlib.h>
using namespace std;
typedef pair<int,int> P;
main(){
  int h,w,n,count=0;
  P zahyou[10];
  queue<P> haba,syokika;
  char maps[1001][1001];
  int min_cost[1001][1001];
  P start,now;
  P kiokua;
  int dx[4]={0,1,0,-1};
  int dy[4]={1,0,-1,0};
  cin>>h>>w>>n;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>maps[i][j];
      min_cost[i][j]=-1;
      if(maps[i][j]=='S'){
	start.first=i;
	start.second=j;
	min_cost[i][j]=0;
      }
      else if(maps[i][j]!='.'&&maps[i][j]!='X'&&maps[i][j]!='S'){
	int a;
	for(int k=1;k<=9;k++){
	  if(maps[i][j]=='0'+k){
	    a=k;
	    break;
	  }
	}
	zahyou[a].first=i;
	zahyou[a].second=j;
      }
    }
  }
  haba.push(start);
  syokika.push(start);
  for(int i=1;i<=n;i++){
    while(!haba.empty()){
      if(haba.front().first==zahyou[i].first&&haba.front().second==zahyou[i].second){
	count=count+min_cost[haba.front().first][haba.front().second];
	while(!syokika.empty()){
	  min_cost[syokika.front().first][syokika.front().second]=-1;
	  syokika.pop();
	}
	min_cost[haba.front().first][haba.front().second]=0;
	kiokua=haba.front();
	while(!haba.empty()){
	  haba.pop();
	}
      }
      else{
	for(int j=0;j<4;j++){
	  int nx,ny;
	  nx=haba.front().first+dx[j];
	  ny=haba.front().second+dy[j];
	  if(nx>=0&&h>nx&&ny>=0&&w>ny&&min_cost[nx][ny]==-1&&maps[nx][ny]!='X'){
	    min_cost[nx][ny]=min_cost[haba.front().first][haba.front().second]+1;
	    P a;
	    a.first=nx;
	    a.second=ny;
	    haba.push(a);
	    syokika.push(a);
	  }
	}
	haba.pop();
      }
    }
    haba.push(kiokua);
    syokika.push(kiokua);
  }
  cout<<count<<endl;
}
      
	  
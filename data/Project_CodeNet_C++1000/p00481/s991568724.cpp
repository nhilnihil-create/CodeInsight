#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<complex>
#define INF 2147483647
#define llINF 9223372036854775807
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long

using namespace std;
int main(){
  int h,w,n;
  cin>>h>>w>>n;
  string Map[h];
  queue<pair<pair<int,int>,int> >que;
  for(int i=0;i<h;i++){
    cin>>Map[i];
    for(int j=0;j<w;j++){
      if(Map[i][j]=='S')
	que.push(mp(mp(i,j),0));
    }
  }
  ll ans=0;
  int hp=1;
  int vx[4]={1,0,-1,0};
  int vy[4]={0,1,0,-1};
  bool used[h+10][w+10]={};
  while(!que.empty()){
    pair<int,int>now=que.front().F;
    int score=que.front().S;
    que.pop();
    //cout<<now.F<<" "<<now.S<<" "<<score<<endl;
    for(int i=0;i<4;i++){
      int x=now.F+vx[i],y=now.S+vy[i];
      if(x>=0&&x<h&&y>=0&&y<w&&!used[x][y]&&Map[x][y]!='X'){
	if('0'<=Map[x][y]&&Map[x][y]<=hp+'0'){
	  memset(used,0,sizeof(used));
	  while(!que.empty())que.pop();
	  que.push(mp(mp(x,y),0));
	  ans+=score+1;
	  hp++;
	  Map[x][y]='.';
	  used[x][y]=true;
	  break;
	}else if(Map[x][y]!='X'){
	  used[x][y]=true;
	  que.push(mp(mp(x,y),score+1));
	}
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}

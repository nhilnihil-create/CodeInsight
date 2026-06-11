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
  int w,h;
  int vx[8]={1,0,-1,0,1,1,-1,-1};
  int vy[8]={0,1,0,-1,1,-1,1,-1};
  while(cin>>w>>h,w+h){
    ll ans=0;
    int Map[h][w]={};
    for(int i=0;i<h;i++)
      for(int j=0;j<w;j++)
	cin>>Map[i][j];
    bool Map2[h][w]={};
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	if(Map2[i][j])continue;
	if(Map[i][j]==0)Map2[i][j]=true;
	else{
	  Map2[i][j]=true;
	  queue<pair<int,int> >que;
	  que.push(mp(i,j));
	  while(!que.empty()){
	    pair<int,int>now=que.front();
	    que.pop();
	    for(int i=0;i<8;i++){
	      int a=now.F+vx[i],b=now.S+vy[i];
	      if(!(a>=0&&a<h&&b>=0&&b<w))continue;
	      if((Map[a][b]==1)&&(!Map2[a][b])){
		Map2[a][b]=true;
		que.push(mp(a,b));
	      }else{
		Map2[a][b]=true;
	      }
	    }
	  }
	  ans++;
	}
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
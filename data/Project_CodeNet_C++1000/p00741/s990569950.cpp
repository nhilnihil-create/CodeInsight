#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int counter=2;
int Map[50][50];
int x[8] = {0,0,1,-1,1,1,-1,-1};
int y[8] = {-1,1,0,0,1,-1,1,-1};
int w,h;

void bfs(int xx,int yy){
  Map[yy][xx]=counter;
  queue<int> q;
  int pos = yy*w+xx;
  q.push(pos);
  while(!q.empty()){
    pos=q.front();
    q.pop();
    yy=pos/w;
    xx=pos%w;
    for(int k=0;k<8;k++){
      int a=xx+x[k];
      int b=yy+y[k];
      if(a < 0 || a >= w || b < 0 || b >= h) continue;
      if(Map[b][a]==1){
	Map[b][a]=counter;
	q.push(b*w+a);
      }
    }
  }
}

int main(){
  while(cin>>w>>h , w+h){
    counter=2;
    memset(Map,0,sizeof(Map));
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	cin>>Map[i][j];
      }
    }

    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	if(Map[i][j]==1){
	  bfs(j,i);
	  counter++;
	  //     	  cout<<" i = "<<i<<" j = "<<j<<endl;
	}
      }
    }
    cout<<counter-2<<endl;
  }
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define OUT(x) cout<<x<<endl
#define DEBUG(x) cout<<#x<<": "<<x
const int BA = 1000;
const int INFTY = (1<<21);
int c[51][51];
int memo[51][51];
int w,h;
int del(int x,int y){
  if(memo[x][y] != -1)return memo[x][y];
  else if(x<0 || y<0 || x==w || y== h)return 0;
  else if(c[x][y]){
    c[x][y] = 0;
    return memo[x][y] = del(x+1,y)+del(x,y+1)+del(x+1,y+1)+
      del(x-1,y-1)+del(x-1,y)+del(x,y-1)+del(x+1,y-1)+del(x-1,y+1);
    
  }
  else return 0;
}

int solve(int x,int y){
  if(x==0 && y == h)return 0;
  else if(x==w){
    return solve(0,y+1);
  }
  else if(c[x][y]){
    del(x,y);
    return solve(x+1,y)+1;
  }
  else return solve(x+1,y);
}

int main(){
  while(cin>>w>>h&&w&&h){
    memset(memo,-1,sizeof(memo));
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	cin >> c[j][i];
      }
    }
    
    cout << solve(0,0) << endl;
  }
}
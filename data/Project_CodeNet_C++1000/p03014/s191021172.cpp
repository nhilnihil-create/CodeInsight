#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;
#define ll long long
#define pb push_back
#define print(x) cout<<(x)<<endl
#define prints(x, y) cout<<(x)<<" "<<(y)<<endl
#define rep(i, n) for(int i = 0; i < (int)n; i++)


int cnt, h, w, xy[2000][2000]={-1};
int L[2000][2000] = {0}, R[2000][2000] = {0}, B[2000][2000] = {0}, U[2000][2000] = {0};
int dx[2] = {1, -1}, dy[2] = {1, -1};
pair<int,int> p;
char c[2000][2000];
queue<pair<int,int> > q;
 
void count_point(){
  // 上方向についてみていく
  rep(i, h){
    rep(j, w){
      if(c[i][j]=='.'){
        if(i == 0) {
          U[i][j] = 1;
        }
        else {
          U[i][j] =  U[i-1][j] + 1;
        } 
      } else {
        U[i][j] = 0;
      }
    }
  }

  // 左方向についてみていく
  rep(i, h){
    rep(j, w){
      if(c[i][j]=='.'){
        if(j == 0) {
          L[i][j] = 1;
        }
        else {
          L[i][j] =  L[i][j-1] + 1;
        } 
      } else {
        L[i][j] = 0;
      }
    }
  }

  for(int i = h-1; i >= 0; i--){
    for(int j = w-1; j >= 0; j--){
      if(c[i][j]=='.'){
        if(i == h-1) {
          R[i][j] = 1;
        }
        else {
          R[i][j] =  R[i+1][j] + 1;
        } 
      } else {
        R[i][j] = 0;
      }
    }
  }
  for(int i = h-1; i >= 0; i--){
    for(int j = w-1; j >= 0; j--){
      if(c[i][j]=='.'){
        if(j == w-1) {
          B[i][j] = 1;
        }
        else {
          B[i][j] =  B[i][j+1] + 1;
        } 
      } else {
        B[i][j] = 0;
      }
    }
  }
}


int32_t main()
{
	cin>>h>>w;
	for(int i =0; i<h; i++)
		for(int j =0; j<w; j++)
			cin>>c[i][j];

  count_point();
  
	for(int i =0; i<h; i++){
    for(int j =0; j<w; j++){
      if(c[i][j]=='.'){
        cnt = max(cnt, R[i][j] + U[i][j] +B[i][j] + L[i][j] - 3);
      }
    }
  }
			
	cout << cnt << endl;
	return 0;
}

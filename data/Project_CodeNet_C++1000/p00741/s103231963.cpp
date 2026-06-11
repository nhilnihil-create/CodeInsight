#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

int history[50][50];
int w,h;
int cnt;

using namespace std;

int search_map(int x,int y,int flag_new,int m[50][50]){

  if(!(x>=0 && x<w && y>=0 && y<h)) return 0;

  if(history[y][x] == 1) return 0;
  else{
    history[y][x]=1;

    if(m[y][x]){

      if(flag_new) cnt++;

      for(int i=-1 ; i<2;i++){
        for(int j=-1 ; j<2;j++){
          if(i==0 && j==0) continue;
          search_map(x+i,y+j,0,m);
        }
      }

    }
    else{
      return 0;
    }

  }

}

int main(void){

  int map[50][50];

  for(cin>>w,cin>>h;w>0 && h>0;cin>>w,cin>>h){
    cnt=0;
    for(int i=0;i<50;i++){
      for(int j=0;j<50;j++){
        history[i][j]=0;
      }
    }
    //cout << w << "," << h << endl;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        cin >> map[i][j];
        //cout << map[i][j] << " ";
      }
      //cout << endl;
    }

    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        search_map(j,i,1,map);
        //cout << map[i][j] << " ";
      }
      //cout << endl;
    }
    cout << cnt << endl;
  }

  return 0;
}


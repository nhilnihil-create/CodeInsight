#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>
#define INF 2000000000
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
#define ll long long
#define PL pair<long long, long long>
#define P pair<int,int>
#define mk make_pair
#define en endl;
#define WHITE 0
#define BLACK 2
#define GRAY 1
#define RE return 0;


int main(){
  while(1){
    ll a,b,n;
    cin>>b>>a;
    if(a==0&&b==0) break;
    bool con[20][20];
    cin>>n;
    for(int i=0; i<=20; i++){
      for(int j=0; j<=20; j++){
        con[i][j]=false;
      }
    }
    for(int i=0; i<n; i++){
      int c,d;
      cin>>c>>d;
      con[c][d]=true;
    }
    
    
//    for(int i=a; i>=1; i--){
//      for(int j=1; j<=b; j++){
//        if(con[j][i]) cout<<'*';
//        else cout<<'.';
//      }
//      cout<<en
//    }
    
    ll ans=0;
    queue<P> michi;
    michi.push(mk(1,1));
    while(!michi.empty()){
      P p=michi.front(); michi.pop();
      for(int i=0; i<2; i++){
        int x=p.first+dx[i],y=p.second+dy[i];
        if(x==b&&y==a) ans++;
        if(!con[x][y]&&x<=b&&y<=a){
          michi.push(mk(x,y));
        }
      }
    }
    
    cout<<ans<<en
  }
  RE
}




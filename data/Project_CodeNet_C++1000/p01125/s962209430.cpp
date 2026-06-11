#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define mod 1000000007 //1e9+7
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 21

void calc(int n){
  int y,x,m,l;
  char dir;
  bool jewel[SIZE][SIZE] = {};
  
  for(int i=0;i<n;i++){
    scanf("%d%d",&x,&y);
    jewel[y][x] = true;
  }

  y = 10;
  x = 10;
  int cc = 0;

  scanf("%d",&m);

  cc += jewel[y][x];
  jewel[y][x] = false;

  for(int i=0;i<m;i++){
    scanf(" %c%d",&dir,&l);

    for(int j=0;j<l;j++){
      if(dir=='N') y += 1;
      if(dir=='W') x -= 1;
      if(dir=='S') y -= 1;
      if(dir=='E') x += 1;

      cc += jewel[y][x];
      jewel[y][x] = false;
    }
  }
  
  if(cc==n) puts("Yes");
  else puts("No");
  
  return;
}

int main(){
  int n;
  
  while(1){
    scanf("%d",&n);
    if(n==0) break;
    calc(n);
  }

  return 0;
}
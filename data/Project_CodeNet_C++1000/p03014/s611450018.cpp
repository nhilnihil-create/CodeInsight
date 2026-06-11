//A.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
const ll mod=1e9+7;

int sx[2020][2020];
int sy[2020][2020];
int main(){
  int h,w;
  cin >> h >> w;
  string s[h];
  rep(i,h){
    cin >> s[i];
  }
  rep(i,h){
    rep(j,w) sx[i][j] = 0;
  }
  int cnt = 0;
  int start,end;
  for(int i = 0; i < h; i++){
    start = 0;
    cnt = 0;
    for(int j = 0; j < w; j++){
      if(s[i].substr(j,1) == "."){
        cnt++;
      }else{
        if(cnt != 0){
          end = j - 1;
          for(int k = start; k <= end; k++){
            sx[i][k] = cnt;
          }
          start = j + 1;
          cnt = 0;
        }else{
          start = j + 1;
          cnt = 0;
        }
      }
    }
    if(cnt != 0){
      for(int k = start; k <= w-1; k++){
        sx[i][k] = cnt;
      }
    }
  }

  rep(i,h){
    rep(j,w) sy[i][j] = 0;
  }

  for(int i = 0; i < w; i++){
    start = 0;
    cnt = 0;
    for(int j = 0; j < h; j++){
      if(s[j].substr(i,1) == "."){
        cnt++;
      }else{
        if(cnt != 0){
          end = j - 1;
          for(int k = start; k <= end; k++){
            sy[k][i] = cnt;
          }
          start = j + 1;
          cnt = 0;
        }else{
          start = j + 1;
          cnt = 0;
        }
      }
    }
    if(cnt != 0){
      for(int k = start; k <= w-1; k++){
        sy[k][i] = cnt;
      }
    }
  }

  int ans = 0;
  rep(i,h){
    rep(j,w){
      ans = max(sx[i][j] + sy[i][j] - 1, ans);
    }
  }
  printf("%d\n", ans);

  return 0;
}

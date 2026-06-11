#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
  double w, h, x, y;
  cin >> w >> h >> x >> y;
  double menseki = w*h/2;
  
  int condition =0;
  if(x==w/2 && y==h/2) condition=1;
  
  printf("%.10f %d", menseki, condition);
  return 0;
  
}
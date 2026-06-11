#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  double w,h,x,y;
  cin >> w >> h >> x >> y;

  double ans = 0;
  int flag = 0;
  
  if(w/2 == x && h/2 == y) flag = 1;
  cout << fixed << w * h / 2 << " " << flag << endl;


  return 0;
}
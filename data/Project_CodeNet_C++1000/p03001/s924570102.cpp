#include <bits/stdc++.h>
using namespace std;
 
int main() {
  //周上あるいは対角線上か調べる
  int64_t W,H,x,y;
  cin >> W >> H >> x >> y;
  int ans = 0;
  
  if(x == W || y == H || x == W/2.0 || y == H/2.0 || x == 0 || y == 0)//周上
    ans = 0;
  
  if(y == x || y == H - x)
    ans = 0;
  
  if(x == W/2.0 && y == H/2.0)
    ans = 1;
  
  
  cout << W*H/2.0 << " " <<   ans <<endl;
  
 
}
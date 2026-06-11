#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
const int ddx[4] = {1,1,-1, -1};
const int ddy[4] = {1,-1,-1,1};
//////////////////////////////////

int c(int x) {
  if(x == 3) return 100000;
  if(x == 2) return 200000;
  if(x == 1) return 300000;
  return 0;
}

int main(){
  int x, y; cin >> x >> y;
  int s = c(x) + c(y);
  if(x == 1 && y == 1) s += 400000;
  cout << s << endl;

  return 0;
}

// EOF

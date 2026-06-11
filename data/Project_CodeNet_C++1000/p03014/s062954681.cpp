// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v) { cout << v << endl; }
template <typename T> void in(T &v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

int main() {
  int h, w; in(h),in(w);
  vector<string> S(h);
  loop(i,0,h) in(S[i]);
  int L[h][w], R[h][w], U[h][w], D[h][w];
  loop(y,0,h) {
    loop(x,0,w) {
      if (x == 0) L[y][x] = S[y][x] == '.';
      else if (S[y][x] == '#') L[y][x] = 0;
      else L[y][x] = L[y][x-1] + 1;
    }
    for (int x=w-1; x>=0; x--) {
      if (x == w-1) R[y][x] = S[y][x] == '.';
      else if (S[y][x] == '#') R[y][x] = 0;
      else R[y][x] = R[y][x+1] + 1;
    }
  }
  
  loop(x,0,w) {
    loop(y,0,h) {
      if (y==0) U[y][x] = S[y][x] == '.';
      else if (S[y][x] == '#') U[y][x] = 0;
      else U[y][x] = U[y-1][x] + 1;
    }
    for (int y=h-1; y>=0; y--) {
      if (y==h-1) D[y][x] = S[y][x] == '.';
      else if (S[y][x] == '#') D[y][x] = 0;
      else D[y][x] = D[y+1][x] + 1;
    }
  }
  
  int max_ = 0;
  loop(y,0,h) loop(x,0,w) {
    max_ = max(max_, L[y][x] + R[y][x] + U[y][x] + D[y][x] - 3);
  }
  cout << max_ << endl;
  return 0;
}

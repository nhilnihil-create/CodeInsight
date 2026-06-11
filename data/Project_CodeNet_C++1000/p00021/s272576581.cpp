#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

#include <complex>
typedef complex<double> Point;
double cross(Point a, Point b){
  return imag(conj(a) * b);
}
struct Line : public vector<Point> {
  Line(Point a, Point b){
    push_back(a);
    push_back(b);
  }
  Point vector(){
    return back() - front();
  }
};
bool parallel(Line l, Line m){
  if(abs(cross(l.vector(), m.vector())) < EPS) return true;
  else return false;
}
Point input(){
  Point p;
  cin >> p.real() >> p.imag();
  return p;
}

int main(){
  int N;
  cin >> N;
  while(N--){
    Point a[4];
    REP(i, 4) a[i] = input();
    if(parallel(Line(a[0], a[1]), Line(a[2], a[3]))){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
  return 0;
}
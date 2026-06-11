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

#include<complex>
typedef complex<double> Point;

double cross(Point a, Point b){
  return imag(conj(a) * b);
}

int ccw(Point a, Point b, Point c){
  b -= a;
  c -= a;
  if(cross(b, c) > EPS) return +1;
  if(cross(b, c) < -EPS) return -1;
  return 0;
}

int main(){
  Point a, b, c, d;
  while(cin >> a.real() >> a.imag() >> b.real() >> b.imag() >> c.real() >> c.imag() >> d.real() >> d.imag()){
    int A = ccw(a, b, d);
    int B = ccw(b, c, d);
    int C = ccw(c, a, d);
    if(A == B && B == C && A != 0){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
  return 0;
}
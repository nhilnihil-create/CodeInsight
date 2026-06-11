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
double dot(Point a, Point b){
  return real(conj(a) * b);
}
double cross(Point a, Point b){
  return imag(conj(a) * b);
}

int ccw(Point a, Point b, Point c){
  b -= a;
  c -= a;
  if(cross(b, c) > EPS) return +1;
  if(cross(b, c) < -EPS) return -1;
  if(dot(b, c) < 0) return +2;
  if(norm(b) < norm(c)) return -2;
  return 0;
}
// テァツつケテ」ツ?古、ツクツ嘉ィツァツ津・ツスツ「abcテ」ツ?ョテ」ツ?ゥテ」ツ?禿」ツ?ォテ」ツ?づ」ツつ凝」ツ?ョテ」ツ?凝・ツ按、テ・ツョツ堙」ツ?凖」ツつ?
enum { OUT, ON, IN };
int contains(Point a, Point b, Point c, Point p){
  int A = ccw(a, b, p);
  int B = ccw(b, c, p);
  int C = ccw(c, a, p);
  if(A == B && B == C && abs(A) == 1) return IN;
  if(!A || !B || !C) return ON;
  return OUT;
}

int main(){
  Point a, b, c, d;
  while(cin >> a.real() >> a.imag() >> b.real() >> b.imag() >> c.real() >> c.imag() >> d.real() >> d.imag()){
    int C = contains(a, b, c, d);
    if(C == IN){
      cout << "YES" << endl;
    }else if(C == OUT){
      cout << "NO" << endl;
    }else if(C == ON){
      cout << "ON!" << endl;
    }
  }
  return 0;
}
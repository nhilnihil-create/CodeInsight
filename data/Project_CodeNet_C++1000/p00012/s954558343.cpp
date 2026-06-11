#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <cassert>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
const double EPS = 1e-9;
const double PI  = acos(-1.0);

#include <complex>
typedef complex<double> P;

double cross(P a, P b) {
    return (a.real() * b.imag() - a.imag() * b.real());
}
double dot(P a, P b) {
    return (a.real() * b.real() + a.imag() * b.imag());
}
int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;           // counter clockwise
  if (cross(b, c) < 0)   return -1;           // clockwise
  if (dot(b, c) < 0)     return +2;           // c--a--b on line
  if (norm(b) < norm(c)) return -2;           // a--b--c on line
  return 0;                                   // a--c--b on line
}
bool triangle_contains(const vector<P>& tri, const P& p) {
	if( ccw(tri[0], tri[1], p) > 0 &&
		ccw(tri[1], tri[2], p) > 0 &&
		ccw(tri[2], tri[0], p) > 0 )
		return true;
	if( ccw(tri[0], tri[1], p) < 0 &&
		ccw(tri[1], tri[2], p) < 0 &&
		ccw(tri[2], tri[0], p) < 0 )
		return true;
	return false;
}

int main(){
	double x1,y1,x2,y2,x3,y3,xp,yp;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>xp>>yp){
		vector<P> triangle;
		triangle.push_back(P(x1,y1));
		triangle.push_back(P(x2,y2));
		triangle.push_back(P(x3,y3));
		bool contains=triangle_contains(triangle,P(xp,yp));
		cout<<(contains?"YES":"NO")<<endl;
	}
}
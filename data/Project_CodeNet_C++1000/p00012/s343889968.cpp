#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#include<string>
#include<complex>
#include<cfloat>

#define f first
#define s second
#define mp make_pair

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define EPS (1e-10)
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef complex<double> P; /* ツ点 */

#define PI (3.1415926535)
#define EPS (1e-10)

//ツ静シツ閉ェ
struct S{
  P p1;
  P p2;
  S(P p,P q) : p1(p), p2(q) {}
};

int ccw(P p0, P p1, P p2){
  P d1 = p1-p0;
  P d2 = p2-p0;
  double dx1 = d1.real(), dx2 = d2.real();
  double dy1 = d1.imag(), dy2 = d2.imag();

  if(dx1*dy2 > dy1*dx2) return  1;//ツ板スツ篠楪計ツ嘉アツづィ
  if(dx1*dy2 < dy1*dx2) return -1;//ツ篠楪計ツ嘉アツづィ
  if((dx1*dx2 < 0) || (dy1*dy2 < 0)) return -1;
  if((dx1*dx1+dy1*dy1) < (dx2*dx2+dy2*dy2)) return 1;
  return 0;
}

bool intersect(const S &s1, const S &s2){
  return ((ccw(s1.p1, s1.p2, s2.p1)
	  *ccw(s1.p1, s1.p2, s2.p2)) <= 0)
       &&((ccw(s2.p1, s2.p2, s1.p1)
	  *ccw(s2.p1, s2.p2, s1.p2)) <= 0);
}

bool inside(P t, P *p, int N){
  int count = 0, j = 0;
  S lt(t, P(DBL_MAX,t.imag()));  

  P pj = p[N-1];
  for(int i=1; i<=N; i++){
    S lp(p[i-1],p[i-1]);
    if(ccw(lt.p1, lt.p2, p[i-1]) != 0){
      if(i == j+1){
	lp.p2 = pj;
	if(intersect(lp,lt)) count++;
      }else if(ccw(lt.p1, lt.p2, p[i-1])*ccw(lt.p1, lt.p2, pj) < 0)
	count++;
      j = i;
      if(j == N) pj = p[0];
      else pj = p[j-1];
    }
  }
  return count & 1 == 1;
}

int main(){
  P p[3];
  P x;
  while(~scanf("%lf%lf%lf%lf%lf%lf%lf%lf",
	       &p[0].real(),&p[0].imag(),
	       &p[1].real(),&p[1].imag(),
	       &p[2].real(),&p[2].imag(),
	       &x.real(),&x.imag())){
    puts(inside(x,p,3)?"YES":"NO");
  }
  return 0;
}
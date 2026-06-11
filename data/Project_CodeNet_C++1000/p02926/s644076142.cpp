#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010

typedef double P_type; //座標(integer or real)
typedef double G_real; //実数の戻り値(float or double or long double)
typedef complex<P_type> P;
const G_real P_eps = 1e-8; //整数の時はゼロ

namespace std{
  template<class T> bool operator<(const complex<T> &a, const complex<T> &b){
    return abs(a.real() - b.real()) < P_eps ? a.imag() + P_eps < b.imag() : a.real() + P_eps < b.real();
  }
};

P rotate(P p, double theta){
  return p * P(cos(theta), sin(theta));
}

//内積
P_type dot(P a, P b) {
  return (a * conj(b)).real();
}

//外積
P_type cross(P a, P b) {
  return (conj(a) * b).imag();
}

//反時計回り
int ccw(P a, P b, P c){
  if(cross(b-a, c-a) > P_eps) return 1; //COUNTER_CLOCKWISE(center:a)
  if(cross(b-a, c-a) < -P_eps) return -1; //CLOCKWISE(center:a)
  if(dot(b-a, c-a) < -P_eps) return -2; //c -> a -> b
  if(dot(a-b, c-b) < -P_eps) return 2; //a -> b -> c
  return 0; //a -> c -> b
}


int main(){
  int N, x[100], y[100];
  pair<P,int> p[200];

  cin >> N;

  for (int i=0; i<N; i++) {
    cin >> x[i] >> y[i];
    p[i] = {arg(P(x[i], y[i])), i};
  }

  sort(p, p+N);

  double ans = 0;

  for (int i=0; i<N; i++) {
    ll sumx = 0, sumy = 0;

    for (int j=i; j<i+N; j++) {
      sumx += x[p[j%N].second];
      sumy += y[p[j%N].second];
      ans = max(ans, sqrt(sumx * sumx + sumy * sumy));
    }
  }

  printf("%.15lf\n", ans);

  return 0;
}

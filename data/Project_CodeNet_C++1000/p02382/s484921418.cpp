#include <bits/stdc++.h>
using namespace std;

# define rep(i, n) for(int(i)=0;(i)<(n);(i)++)
# define reps(i, n) for(int(i)=1;(i)<=(n);(i)++)
# define rrep(i, n) for(int i=((int)(n)); i>0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>=0; --i)
# define ALL(v) v.begin(), v.end()
template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<typename T> void dump(T e){std::cout << e << std::endl;}
template<typename T> void dump(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void dump(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ dump(v); } }
typedef long long ll;


int main(){
  int n; cin >> n;
  vector <double> x(n);
  vector <double> y(n);
  rep(i,n) cin >> x[i];
  rep(i,n) cin >> y[i];
  
  double p1=0;
  double p2=0;
  double p3=0;
  double p_i=-1;
  rep(i,n) {
    p1 += abs(x[i]-y[i]);
    p2 += pow(abs(x[i]-y[i]),2);
    p3 += pow(abs(x[i]-y[i]),3);
    p_i = (p_i >= abs(x[i]-y[i]))? p_i:abs(x[i]-y[i]);
  }
  printf("%.6lf\n",p1);
  printf("%.6lf\n",sqrt(p2));
  printf("%.6lf\n",cbrt(p3));
  printf("%.6lf\n",p_i);
}


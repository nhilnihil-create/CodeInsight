#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vector<double> x(n), y(n);
  rep(i,n) cin >> x[i] >> y[i];
  vi v(n);
  rep(i,n) v[i] = i;
  double sum = 0;
  do{
    double len = 0;
    rep(i,n-1){
      double dist = pow(x[v[i]]-x[v[i+1]], 2) + pow(y[v[i]]-y[v[i+1]], 2);
      dist = pow(dist, 0.5);
      len += dist;
    }
    sum += len;
  }while(next_permutation(v.begin(),v.end()));
  int kai = 1;
  rep(i,n) kai *= i+1;
  sum /= kai;
  printf("%.7f", sum);
}

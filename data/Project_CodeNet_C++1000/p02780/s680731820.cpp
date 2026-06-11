#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
#define rep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

int main(){
  int n, k;
  cin >> n >> k;
  vector<double> p(n);
  
  rep(i, 0, n){
    double a;
    cin >> a;
    a += 1.0;
    a /= 2.0;
    p[i] = a;
  }
  
  double sum = 0.0;
  
  rep(i, 0, k){
    sum += p[i];
  }
  
  double mx = sum;
  
  rep(i, 0, n-k){
    sum -= p[i];
    sum += p[i+k];
    if(mx < sum)
      mx = sum;
  }
  
  cout << fixed << setprecision(10);
  cout << mx << endl;
  
  return 0;
  
}
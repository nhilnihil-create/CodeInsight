#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n;
  cin >> n;

  vector<double> v(n);
  rep(i,n) cin >> v.at(i);
  sort(v.rbegin(), v.rend());
  stack<double> s;
  rep(i,n){
    s.push(v.at(i));
  }

  while (s.size() != 1){
    double a, b, c;
    a = s.top(); s.pop();
    b = s.top(); s.pop();
    c = (a + b) / 2;
    s.push(c);
  }

  double ans = s.top();
  printf("%.10f\n", ans);
  return 0;
}

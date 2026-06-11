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

  vi a(n+1);
  vi b(n);
  ll sum = 0;
  rep(i,n+1){
    cin >> a.at(i);
    sum += a.at(i);
  }
  rep(i,n) cin >> b.at(i);

  rep(i,n){
    a.at(i) = max(a.at(i), 0);
    if (a.at(i) >= b.at(i)) a.at(i) -= b.at(i);
    else {
      a.at(i+1) -= b.at(i) - a.at(i);
      a.at(i) = 0;
    }
  }
  ll res = 0;
  rep(i,n+1){
    a.at(i) = max(a.at(i), 0);
    res += a.at(i);
    //printf("a.at(%d)=%d\n", i, a.at(i));
  }
  //printf("sum: %ld, res:%ld\n", sum, res);

  ll ans = sum - res;
  cout << ans << endl;
  return 0;
}

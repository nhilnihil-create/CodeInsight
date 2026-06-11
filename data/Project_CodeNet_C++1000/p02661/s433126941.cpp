#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i,n) cin >> a[i] >> b[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  ll MIN;
  ll MAX;
  if(n%2==1){//Nが奇数の場合
    MIN = a[n/2];
    MAX = b[n/2];
  }
  else{//Nが偶数の場合
    MIN = a[n/2] + a[n/2-1];
    MAX = b[n/2] + b[n/2-1];
  }
  int ans = MAX - MIN + 1;

  cout << ans << endl;

  return 0;
}
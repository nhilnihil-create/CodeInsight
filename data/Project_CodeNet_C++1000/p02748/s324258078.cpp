#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main(){
  ll A = 0,B = 0,M = 0,ans = 1000000000;
  cin >> A >> B >> M;
  vector<ll>a(A);
  rep(i,A){
    cin >> a[i];
  }
  vector<ll>b(B);
  rep(i,B){
    cin >> b[i];
  }
  ll x = 0,y = 0,c = 0;
  rep(i,M){
    cin >> x >> y >> c;
    ans = min(ans, a[x - 1] + b[y - 1] - c);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  ans = min(a[0] + b[0],ans);
  cout << ans;
}
#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  int X, Y, A, B, C; cin >> X >> Y >> A >> B >> C;
  int p[A], q[B], r[C];
  rep(i,A) cin >> p[i];
  rep(i,B) cin >> q[i];
  rep(i,C) cin >> r[i];
  sort(p,p+A,greater<int>());
  sort(q,q+B,greater<int>());
  vector<int> vec;
  rep(i,X) vec.push_back(p[i]);
  rep(i,Y) vec.push_back(q[i]);
  rep(i,C) vec.push_back(r[i]);

  sort(all(vec));
  reverse(all(vec));
  ll ans = 0;
  rep(i,X+Y) ans += vec[i];
  cout << ans << endl;

  // cout << fixed << setprecision(10);
  
  return 0;
}

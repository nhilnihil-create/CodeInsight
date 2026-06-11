#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

vector<int> prime(int N) {
  vector<bool> a(N, true);
  for(int i=1; i<sqrt(N); i++) {
    if(a[i]) for(int k=2; (i+1)*k-1<N; k++) a[(i+1)*k-1] = false;
  }
  vector<int> p;
  rep(i, N) if(a[i]) p.push_back(i+1);
  p.erase(p.begin());
  return p;
}

signed main() {
  int X, Y, A, B, C; cin >> X >> Y >> A >> B >> C;
  vector<int> p(A), q(B), r(C);
  rep(i, A) cin >> p[i];
  rep(i, B) cin >> q[i];
  rep(i, C) cin >> r[i];
  
  sort(all(p));
  reverse(all(p));
  sort(all(q));
  reverse(all(q));
  sort(all(r));
  reverse(all(r));
  
  priority_queue<int, vector<int>, greater<int>> ab;
  
  int ans = 0;
  rep(i, X) {
    ans += p[i];
    ab.push(p[i]);
  }
  rep(i, Y) {
    ans += q[i];
    ab.push(q[i]);
  }
  
  rep(i, C) {
    if(r[i] > ab.top()) {
      ans += r[i] - ab.top();
      ab.pop();
    } else break;
  }
  
  cout << ans << endl;

  

}
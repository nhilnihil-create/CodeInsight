#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

int main() {
  int N; cin >> N;
  int P[N]; rep(i,N) { cin >> P[i]; P[i]--; }
  int pos[N]; rep(i,N) pos[(N-1)-P[i]] = i;
  multiset<int> gr;
  gr.insert(-1); gr.insert(-1);
  gr.insert(N); gr.insert(N);
  ll result = 0;
  rep(i,N) {
    auto r1 = gr.upper_bound(pos[i]);
    auto r2 = r1; r2++;
    auto l1 = r1; l1--;
    auto l2 = l1; l2--;
    ll tmp = (pos[i]-*l1)*(*r2-*r1) + (*r1-pos[i])*(*l1-*l2);
    result += tmp * (N-i);
    // cout << *l2 << " " << *l1 << " " << *r1 << " " << *r2 << endl;
    // cout << N-i << ":" << tmp << endl;
    gr.insert(pos[i]);
  }
  cout << result << endl;
  return 0;
}
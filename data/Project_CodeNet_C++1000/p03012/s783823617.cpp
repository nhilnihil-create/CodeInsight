#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define be(v) v.begin(), v.end()
#define ll long long
ll INF = 1e9;

int main() {
  int n; cin >> n;
  vector<int> w(n);
  int ans = 0;
  rep(i,n) {
  	cin >> w[i];
  	ans+=w[i];
  }
  int mi = ans;
  int p_sum=0;
  rep(i,n) {
  	p_sum+=w[i];
  	mi = min(mi,abs(p_sum-(ans-p_sum)));
  }
  cout << mi << endl;
}

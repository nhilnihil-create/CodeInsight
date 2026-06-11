#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
  string s;
  cin >> s;
  int n = s.length();
  vector<int> left(n + 1), right(n + 1);
  rep(i, n) {
    if (s[i] == '<') left[i + 1] = left[i] + 1; 
  }

  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '>') right[i] = right[i + 1] + 1;
  }

  ll ans = 0;
  rep(i, n + 1) ans += max(left[i], right[i]);
  cout << ans << endl;
}
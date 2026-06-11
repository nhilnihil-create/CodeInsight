#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<int> cnt(n+1,0);
  vector<int> seq(n, 0);
  rep(i, n) {
    cin >> seq.at(i);
    cnt.at(seq.at(i))++;
  }
  ll tot = 0;
  reps(i,1, n+1) {
    ll v = cnt.at(i);
    tot += v * (v-1) / 2;
  }
  rep(i, n) {
    ll v = cnt.at(seq.at(i));
    if (v == 0) {
      cout << tot << endl;
    } else {
      ll sub = v * (v - 1) / 2;
      ll add = (v - 1) * (v - 2) / 2;
      cout << tot - sub + add << endl;
    }
  }
  return 0;
} 
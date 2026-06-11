#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define INF 1999999999
#define MODA 1000000007 
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main() {
  ll N;
  cin >> N;
  string S;
  cin >> S;

  ll ans = 0;
  for (ll i = 0; i < 1000; ++i) {
    string nstr = to_string(i);
    while(nstr.size() < 3) {
      nstr = "0" + nstr;
    }
    ll digit = 0;
    for (auto str : S) {
      if (str == nstr[digit]) digit++;
      if (digit == 3) {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;

  return 0;
}


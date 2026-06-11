#include <bits/stdc++.h>
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)

typedef unsigned long long ull;
typedef long long ll;

const int INF = 1001001001;
const int MOD = 1000000007;

using namespace std;
using P = pair<int,int>;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }


int main() {
  vector<ll> foods{ 100, 101, 102, 103, 104, 105 };
  ll x;
  cin >> x;

  bool able = false;
  for (int i = 1; 100*i <= x; i++) {
      ll rem = x - 100*i;
      if (0<=rem && rem<=5*i) able = true;
  }
  cout << able << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007LL;

int main() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll cnt = 0LL;
  rep(i,n) if(s[i]=='R') cnt++;
  ll cnt2 = 0LL;
  rep(i,cnt) if(s[i]=='R') cnt2++;
  ll ans = cnt - cnt2;
  cout << min(ans,n-ans) << endl;
  return 0;
}
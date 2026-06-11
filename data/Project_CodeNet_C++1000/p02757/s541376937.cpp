#include <bits/stdc++.h>
using namespace std;

#define sz(x) int(x.size())
#define Task "abc"
#define For(i, a, b) for(int i = (a), _b = (b); i <= b; ++i)
#define All(x) (x).begin(), (x).end()
#define mp make_pair

typedef long long ll;

const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;

ll Pow10[maxn];
char s[maxn];
int p, n;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
//  freopen(Task".inp", "r", stdin);  freopen(Task".out", "w", stdout);
  cin >> n >> p;
  cin >> s + 1;
  if (p == 2 || p == 5){
    ll ret = 0;
    for (int i = 1; i <= n; ++i){
      int c = s[i] - '0';
      if (c % p == 0) ret += i;
    }
    cout << ret;
    return 0;
  }
  Pow10[0] = 1;
  for (int i = 1; i <= n; ++i) Pow10[i] = Pow10[i-1] * 10, Pow10[i] %= p;
  ll ans = 0;
  vector<int> cnt(p + 1, 0);
  cnt[0]++;
  ll val = 0;
  for (int i = n; i >= 1; --i){
    int c = s[i] - '0';
    val = Pow10[n - i + 1] * c + val; val %= p;
    ans += cnt[val];
    cnt[val]++;
  }
  cout << ans;
}



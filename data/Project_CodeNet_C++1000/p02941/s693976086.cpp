#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define fst first
#define snd second
#define PI (acos(-1))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define MAXN 1123456
#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin>>n;
  vi a(n), b(n);
  rep(i,0,n)cin>>a[i];
  rep(i,0,n)cin>>b[i];
  ll ans = 0;
  priority_queue<pii> pq;
  rep(i,0,n) if (b[i] > a[i]) pq.push({b[i], i});
  bool good=true;
  while (!pq.empty()) {
    int wtf = pq.top().fst;
    int m = pq.top().snd;
    pq.pop();
    if (b[m] != wtf) continue;
    int y=max(a[m],max(b[(m-1+n)%n], b[(m+1)%n]));
    int sum = b[(m-1+n)%n] + b[(m+1)%n];
    int k = ((b[m] - y + sum - 1) / sum);
    b[m] -= k * sum;
    ans += k;
    if (b[m] != a[m])
      pq.push({b[m],m});
    if (b[m] < a[m]) break;
  }
  rep(i,0,n) {
      if (a[i]!=b[i]) {
        good=false;
        break;
      }
    }
  if (good)cout<<ans<<endl;
  else cout<<-1<<endl;
}


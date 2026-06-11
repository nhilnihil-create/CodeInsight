#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll

#define INF 1e16
#define mod 1000000007

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll K, Q;
  cin >> K >> Q;
  vector<ll> D(K);
  rep(i, K) cin >> D[i];
  while(Q--) {
  	ll N, X, M;
  	cin >> N >> X >> M;
  	vector<ll> d(K);
  	rep(i, K) d[i] = D[i] % M;

  	ll zcnt = 0;
  	rep(i, K) if(d[i] == 0) zcnt++;
  	zcnt *= (N - 1) / K;
  	rep(i, (N - 1) % K) if(d[i] == 0) zcnt++;

  	ll sum = X;
  	ll dsum = 0;
  	rep(i, K) dsum += d[i];
  	sum += dsum * ((N - 1) / K);
  	rep(i, (N - 1) % K) sum += d[i];
  	ll cnt = sum / M;
  	cnt -= X / M;

  	ll res = N - 1 - zcnt - cnt;
  	cout << res << "\n";
  }

  return 0;
}

#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<iomanip>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

const int MAX = 510000;
const int MOD = 1000000007;
ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}


int main(){
  ll N, M; cin >> N >> M;
  vector<ll> a(N); rep(i,N) cin >> a[i];
  vector<ll> b(N); rep(i,N) b[i] = a[i]; rep(i,N) b[i] /= 2;


  // それぞれが何回2でわれるかを保存していく
  vector<ll> cnt(N);
  rep(i,N){
    while(a[i] % 2 == 0){
      a[i] /= 2;
      cnt[i]++;
    }
  }
  rep(i,N - 1){
    if(cnt[i] != cnt[i + 1]){
      cout << 0 << endl;
      return 0;
    }
  }

  // 何個あるか　最初の値から　2倍ずつ離れる
  ll lcm = b[0];
  rep(i,N){
    lcm = lcm * b[i] / gcd(lcm , b[i]);
    if(lcm > M){
      cout << 0 << endl;
      return 0;
    }
  }
  if(lcm > M) cout << 0 << endl;
  else {
    ll ans = (M - lcm) / (2 * lcm) + 1;
    cout << ans << endl;
  }
}

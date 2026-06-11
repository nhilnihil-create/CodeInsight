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

int main(){
  ll N , K; cin >> N >> K;
  vector<ll> a(N); rep(i,N) cin >> a[i];

  rep(loop , K){
    vector<ll> b(N + 1);
    rep(i,N) b[max( (ll)0 , i - a[i])]++;
    rep(i,N) b[min(N , i + a[i] + 1)]--;
    rep(i,N) b[i + 1] += b[i];
    if(a == b) break;
    a = b;
  }
  rep(i,N) cout << a[i] << " "; cout << endl;
}

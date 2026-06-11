#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for(int i = (a);i <= (b);i++)
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 10;
const double eps = 1e-8;
const double pi = acos(-1.0);
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return a * b / gcd(a,b);}
ll poww(ll x,ll y,ll p){ll ans = 1;while(y){if(y & 1) ans = ans * x % p;x = x * x % p;y >>= 1;}return ans % p;}
bool isp(ll x){if(x < 2) return 0; for(ll i = 2;i * i <= x;i++){if(x % i == 0) return 0;}return 1;}
ll n,k,a[maxn],f[maxn];
bool check(ll x){
	ll sum = 0;
	for(int i = 0;i < n;i++){
		ll b = a[i],c = f[i];
		if(b * c > x){
			sum += (b - x / c);
		}
	}
	return sum <= k;
}
void calc(){
	ll l = 0,r = 1e18,ans = 0;
	while(l <= r){
		ll mid = (l + r) >> 1;
		if(check(mid)) r = mid - 1,ans = mid;
		else l = mid + 1;
	}
	cout << ans << endl;
}
void solve(){
	sort(a,a+n);
	sort(f,f+n,greater<ll>());
	calc();	
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	rep(i,0,n-1) cin >> a[i];
	rep(i,0,n-1) cin >> f[i];
	solve();
}
//do smt instead of nothing! never give up!

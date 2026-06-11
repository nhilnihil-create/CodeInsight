#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
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
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;
const double eps = 1e-8;
const double pi = acos(-1.0);
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return a * b / gcd(a,b);}
ll poww(ll x,ll y,ll p){ll ans = 1;while(y){if(y & 1) ans = ans * x % p;x = x * x % p;y >>= 1;}return ans % p;}
bool isp(ll x){if(x <= 1) return 0; for(ll i = 2;i * i <= x;i++){if(x % i == 0) return 0;}return 1;}
ll n,d,a,ans;
ll diff[maxn]; //差分数组 d[i]：第i只怪物轰炸次数-第i-1只怪物轰炸次数 
pll p[maxn];
int main(){
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> d >> a;
	for(int i = 1;i <= n;i++) cin >> p[i].fi >> p[i].se;
	sort(p + 1,p + n + 1);
	for(int i = 1;i <= n;i++){
		diff[i] += diff[i-1]; //前缀和,统计该点实际轰炸次数
		ll h = p[i].se;
		h -= diff[i] * a;
		if(h <= 0) continue;
		ll cnt = (h + a - 1) / a;
		diff[i] += cnt;
		ans += cnt;
		ll l = 1,r = n,nx = r;
		while(l <= r){
			ll mid = (l + r) >> 1;
			if(p[mid].fi <= p[i].fi + 2 * d) l = mid + 1,nx = mid;
			else r = mid - 1;
		} 
		diff[nx + 1] -= cnt;
	}
	cout << ans << endl;
	return 0;
}
//do smt instead of nothing! never give up!
//take care of long long!
//take care of upper or lower case e.g "yes" or "YES"?
//boundary condition! e.g. n = 0?
//brute force is always the first choice!
// print the ans to look for patterns in the data!
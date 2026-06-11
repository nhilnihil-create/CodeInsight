#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
const int maxc = 26;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-8;
inline int read(){
    int f = 1,x = 0; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - 48;ch = getchar();}
    return f * x;
}
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
ll qw(ll x,ll y){ll ans = 1;while(y){if(y&1) ans *= x;x *= x;y >>= 1;}return ans;}
ll poww(ll x,ll y,ll p){ll ans = 1;while(y){if(y & 1) ans = ans * x % p;x = x * x % p;y >>= 1;}return ans % p;}
bool is_prime(ll x){if(x <= 1) return 0;for(ll i = 2;i * i <= x;i++){if(x % i == 0) return 0;}return 1;	}
string s,t;
int ans;
int main()
{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s >> t;
	for(int i = 0;i < 3;i++){
		if(s[i] == t[i]) ans++;
	}			
	cout << ans << endl;
	return 0;	
}
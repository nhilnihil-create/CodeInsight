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
const int maxn = 2e5 + 5;
const double eps = 1e-8;
const double pi = acos(-1.0);
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return a * b / gcd(a,b);}
ll poww(ll x,ll y,ll p){ll ans = 1;while(y){if(y & 1) ans = ans * x % p;x = x * x % p;y >>= 1;}return ans % p;}
bool isp(ll x){if(x < 2) return 0; for(ll i = 2;i * i <= x;i++){if(x % i == 0) return 0;}return 1;}
int m1,m2,d1,d2;
int m[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> m1 >> d1 >> m2 >> d2;
	if(m[m1] == d1) cout << 1;
	else cout << 0;
	cout << endl;	
	return 0;
}
//do smt instead of nothing! never give up!
//take care of long long!
//take care of upper or lower case e.g "yes" or "YES"?
//boundary condition! e.g. n = 0?
//brute force is always the first choice!
// print the ans to look for patterns in the data!
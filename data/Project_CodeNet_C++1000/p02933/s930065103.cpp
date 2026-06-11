#pragma region
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define vi vector<int>
#define vd vector<double>
#define vs vector<string>
#define repi(i, m, n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i, n) repi(i, 0, n)
#define revi(i, m, n) for(int i=(int)(m-1);i>=(int)(n);i--)
#define rev(i, n) revi(i, n, 0)
#define each(i, n) for(auto&& i: n)
#define sz(v) ((int)(v).size()) 
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define uniq(v) (v).erase(unique((v).begin(), (v).end()), (v).end());
#define dump(x) cerr << #x << " = " << x << endl
#define gcd __gcd
int lcm(int a, int b){return a / gcd(a, b) * b;}
const int INF = 1e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-15;
const double PI = acos(-1);
int dig(int n){return (int)(log10(n) + 1);}
int abc(char x){return (int)(x)-(int)('a');} // 0~25
char abc(int x){return (char)(x+(int)('a'));} 
int ABC(char x){return (int)(x)-(int)('A');}
char ABC(int x){return (char)(x+(int)('A'));}
void solve();
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	solve();
}
#pragma endregion

void solve() {
	int a; string s;
	cin >> a >> s;
	if (a < 3200) s = "red";
	cout << s << endl;
}
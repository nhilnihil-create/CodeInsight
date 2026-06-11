#include <bits/stdc++.h>
using namespace std;
#define fast_io cin.tie(0);ios_base::sync_with_stdio(0);
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cout << endl; }
void show() { cout << endl; }
void pret() { cout << endl; exit(0);}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cout << " " << to_string(H); debug_out(T...);}
template <typename Head, typename... Tail> void show(Head H, Tail... T) {cout <<H<<" "; show(T...);}
template <typename Head, typename... Tail> void pret(Head H, Tail... T) {cout <<H<<" "; pret(T...);}
#define pr(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
typedef long long ll;
// #define int ll
typedef long double ld;
#define disp(x) cout<<x<<" ";
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define fo(i,a,b) for(int i=a;i<=(int)b;i++)
#define rf(i,a,b) for(int i=a;i>=(int)b;i--)
#define mp make_pair
#define pb emplace_back
#define F first
#define S second
#define endl '\n'
//cout.setf(ios::fixed);cout.precision(18)
const int MOD = 1e9+7;
const int maxn = 100000+10;

vector<pair<int, int> > v[maxn];
int ans[maxn], value;

void dfs(int id, int par, int exclude){
	int curr = 1;
	for(const auto &it:v[id]){
		if(it.first == par) continue;
		if(curr == exclude) curr++;
		ans[it.second] = curr++;
		value = max(value, curr - 1);
		dfs(it.first, id, curr - 1);
	}
}

int32_t main(){
	fast_io;
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;
		cin >> x >> y;
		v[x].emplace_back(y, i);
		v[y].emplace_back(x, i);
	}
	dfs(1, -1, -1);
	show(value);
	for (int i = 0; i < n - 1; ++i)
	{
		show(ans[i]);
	}
	return 0;
}
#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<cstdlib>
#include<time.h>
#include<string>
#include<stack>
#include<cmath>
#include<iostream>
#include<cstring>
#include<complex>
#include<tr1/unordered_set>
#include<tr1/unordered_map>
#define INF  (int)1e9
#define EPS   1e-9
#define MOD 1000000007
#define Pi 3.14159
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
// input macro
#define IN(x,n)   for(int e=0;e<n;e++){ll y;cin>>y;x.pb(y);}
//output macro
#define print(x)    for(auto it:x) cout<<it<<' '; cout<<endl;
#define printPI(x)  for(auto it:x) cout<<it.F<<' '<<it.S<<'\t';  cout<<endl;
// shortcut for data type
#define ll long long
#define PI pair<int,int>
#define PL pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<VI>
#define vvl vector<VL>
#define vvvi vector<VVI>
#define vvvl vector<VVL>
#define vpi vector<PI>
#define vpl vector<PL>
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define uset unordered_set
#define umap unordered_map
#define dbg(x, y) cout << x << " = " << y << endl
using namespace std;


const int Ntest = 1e5 + 5;


ll gcd(ll a, ll b) {ll temp; while (b > 0) {temp = a % b; a = b; b = temp;} return a;}
ll lcm(ll a, ll b) {return a * b / gcd(a, b);}
ll fpow(ll  b, ll exp, ll mod) {if (exp == 0) return 1; ll t = fpow(b, exp / 2, mod); if (exp & 1) return t * t % mod * b % mod; return t * t % mod;}
ll divmod(ll i, ll j, ll mod) {i %= mod, j %= mod; return i * fpow(j, mod - 2, mod) % mod;}

clock_t time_p = clock();
void TimeTaken()
{
	time_p = clock() - time_p;
	cerr << "Completion time : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
vi v[100001];
int p[100001], k[100001];
bool ans = true;

void sol() {
	ll n, sum, ans;
	ll a[200005];
	cin >> n;

	sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum = sum ^ a[i];
	}
	for (int i = 0; i < n; i++) {
		ans = 0;
		if (i != 0)
			cout << ' ';
		ans = sum ^ a[i];
		cout << ans;
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--)
		sol();

	return 0;
}
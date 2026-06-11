#include <bits/stdc++.h>
using namespace std;
// Macros for easier access
#define ll long long
#define endl '\n'
#define F first
#define S second
#define umap unordered_map
#define uset unordered_set
#define test ll cases; cin>>cases; for(ll testCase = 1; testCase <= cases; testCase++)   //test cases
#define fill(name, val) memset(name, val, sizeof(name));
#define mop(a, op, b)    (a%mod op b%mod)%mod
#define error(x) fixed<<setprecision(x) //cout<<error(5)<<someDouble    -> example - 3.14159
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define get(a, n)    for(ll i = 0; i < n; i++)    cin>>a[i];
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug(x) cerr << #x << " : " << (x) << endl
// Constants
#define MX 100001
#define mod 1000000007LL
#define inf 1000000000000000000LL
void init(){
	boost;
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

/*	Author: 🆉🅴🅽🅾🅻🆄🆂	*/

ll n, m, q, a[50][4], A[10];
ll calc(ll i, ll cm){
	if(i == n){
		ll score = 0;
		for(ll j = 0; j < q; j++)
			if(A[a[j][1]-1] - A[a[j][0]-1] == a[j][2])	score += a[j][3];
		return score;
	}
	ll ans = 0;
	for(ll j = cm; j <= m; j++){
		A[i] = j;
		ans = max(ans, calc(i+1, j));
	}
	return ans;
}
int main(){
	init();
	cin>>n>>m>>q;
	for(ll i = 0; i < q; i++)	cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
	cout<<calc(0, 1);
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fore(b,c) for(int val0=b;val0<c;val0++)
#define forr(k,c,s) for(int k=c;k<s;k++)
#define pb push_back
#define mmp make_pair
#define oset(T) tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long double ld;
typedef vector<vii> al;
typedef vector<ll> vl;
const int INF = 1e9;
const ll INFL = 1LL<<61;
const ll M = 998244353;
const int MN = 200200;
ll fr[MN];
ll mul(ll a, ll b) {return (a*b)%M;}
ll bp(ll b, ll p) {
	ll ac = 1;
	while(p) {
		if(p&1) {
			ac = mul(ac,b);
		}
		b = mul(b,b);
		p >>= 1;
	}
	return ac;
}
ll w[MN];
int main() {
	ios::sync_with_stdio(0);cout.precision(20);cout.tie(0);cin.tie(0);
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> w[i];
		fr[w[i]]++;
	}
	ll tot = 1;
	if(fr[0] != 1) {
		tot = 0;
	}
	if(w[0] != 0) {
		tot = 0;
	}
	for(int i=1;i<n;i++) {
		tot = mul(tot,bp(fr[i-1],fr[i]));
	}
	cout << tot << '\n';
}

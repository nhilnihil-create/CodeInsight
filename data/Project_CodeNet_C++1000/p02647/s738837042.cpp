#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fore(b,c) for(int val0=b;val0<c;val0++)
#define forr(k,c,s) for(int k=c;k<s;k++)
#define pb push_back
#define mmp make_pair
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

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
vl w;
int main() {
	ios::sync_with_stdio(0);cout.precision(20);cout.tie(0);cin.tie(0);
	ll n,k;
	cin >> n >> k;
	for(int i=0;i<n;i++) {
		ll t;
		cin >> t;
		w.push_back(t);
	}
	for(int it=0;it<k;it++) {
		ll lc = 0;
		vl nu(w.size(),0);
		vl ru(w.size(),0);
		vl ac(w.size(),1);
		for(int i=0;i<n;i++) {
			if(i+1 < n) {
				nu[i+1]++;
			}
			if(i+w[i]+1 < n) {
				nu[i+w[i]+1]--;
			}
			if(i-1 >= 0) {
				ru[i-1]++;
			}
			if(i-w[i]-1 >= 0) {
				ru[i-w[i]-1]--;
			}
		}
		ll rs = 0;
		for(int i=0;i<n;i++) {
			rs += nu[i];
			ac[i] += rs;
		}
		rs = 0;
		for(int i=n-1;i>=0;i--) {
			rs += ru[i];
			ac[i] += rs;
		}
		w = ac;
		bool lo = true;
		for(int i=0;i<n;i++) {
			if(ac[i] != n) {lo = false;break;}
		}
		if(lo) {break;}
	}
	for(int i=0;i<n;i++) {
		if(i > 0) {cout << " ";}
		cout << w[i];
	}
	cout << '\n';
}


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pci pair <char, int>
#define pld pair <ld, ld>
#define ppld pair <pld, pld>
#define ppll pair <pll, pll>
#define pldl pair <ld, ll>
#define vll vector <ll>
#define vvll vector <vll>
#define vpll vector <pll>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define mll map <ll, ll>
#define fastmap gp_hash_table
#define cd complex <double>
#define vcd vector <cd>
#define PI 3.14159265358979
#define ordered_set tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update>
#pragma 03
using namespace std;
using namespace __gnu_pbds;
ll mod = 1e9 + 7;
int main(){
 	ll n; string s; cin >> n >> s;
	ll cnt = 0, ans = 1;
	for (ll i = 0; i < 2 * n; i++){
		ll k = cnt % 2;
		if (s[i] == 'B') k ^= 1;
		if (k == 1) cnt++;
		else if (cnt > 0){
			(ans *= cnt) %= mod; cnt--;
		}
		else{
			cout << 0 << endl; return 0;
		}
	}
	if (cnt > 0){
		cout << 0 << endl; return 0;
	}
	for (ll i = 1; i <= n; i++) (ans *= i) %= mod;
 	cout << ans << endl;
}
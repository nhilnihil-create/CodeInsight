/* 
	Author: ankrypt
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define MOD 1000000007
#define ll long long int
#define u64 unsigned long long int
#define ff first
#define ss second
#define all(x) x.begin(), x.end() 
#define ub upper_bound
#define lb lower_bound
#define MAX_INT 15
#define fi(a, b, c, d) for(int a = b; a < c; a += d)
#define fl(a, b, c, d) for(ll a = b; a < c; a += d)
#define fei(a, b, c, d) for(int a = b; a <= c; a += d)
#define fel(a, b, c, d) for(ll a = b; a <= c; a += d)
#define quit exit(0)

ll N, M, A, B, C;
ll arr[MAX_INT], arr1[MAX_INT], data[MAX_INT];
vector<ll> V;

ll modSum(ll A, ll B, ll C) {
	return (A + B) % C;
}
ll modMul(ll A, ll B, ll C) {
	return (A * B) % C;
}

int main() {
	scanf("%lld %lld", &N, &M);
	string S = "";
	cin >> S;
	ll rem = 0;
	ll val = 1;
	ll ans = 0;
	ll ans2 = 0;
	ll ans5 = 0;
	ll ans10 = 0;
	unordered_map<ll, ll> mp;
	mp[0]++;
	if(M == 2 || M == 5 || M == 10) {
		fi(i, 0, S.size(), 1) {
			if((S[i] - '0') % 2 == 0) {
				ans2 += i + 1;
			}
			if((S[i] - '0') % 5 == 0) {
				ans5 += i + 1;
			}
			if((S[i] - '0') % 10 == 0) {
				ans10 += i + 1;
			}
		}
	}
	if(M == 2) {
		cout << ans2 << "\n";
		quit;
	}
	if(M == 5) {
		cout << ans5 << "\n";
		quit;
	}
	if(M == 10) {
		cout << ans10 << "\n";
		quit;
	}
	for(int i = S.size() - 1; i >= 0; i--) {
		rem = (modSum(rem, modMul(val, (S[i] - '0'), M), M));
		ans += mp[rem];
		mp[rem]++;
		val = modMul(10, val, M);
	}
	cout << ans << "\n";

	return 0;
}
/*
	Powered by Buggy Plugin
*/



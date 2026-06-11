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
#define MAX_INT 55
#define fi(a, b, c, d) for(int a = b; a < c; a += d)
#define fl(a, b, c, d) for(ll a = b; a < c; a += d)
#define fei(a, b, c, d) for(int a = b; a <= c; a += d)
#define fel(a, b, c, d) for(ll a = b; a <= c; a += d)
#define quit exit(0)

ll N, M, A[MAX_INT], B[MAX_INT], C[MAX_INT], D[MAX_INT], K;
ll arr[MAX_INT], arr1[MAX_INT], arr2[MAX_INT], arr3[MAX_INT];
vector<ll> V;
ll finalAns = 0;

void rec(ll ind) {
	if(ind > N) {
		int flag = 1;
		ll ans = 0;
		fi(i, 0, K, 1) {
			if(arr[B[i]] - arr[A[i]] != C[i]) {}
			else {
				ans += D[i];
			}
		}
		finalAns = max(finalAns, ans);
		return;
	}
	fei(i, arr[ind - 1], M, 1) {
		if(!i) {}
		else {
			arr[ind] = i;
			rec(ind + 1);
		}
	}
} 


int main() {
	cin >> N >> M >> K;
	fi(i, 0, K, 1) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	rec(1);
	cout << finalAns << "\n";

	return 0;
}
/*
	Powered by Buggy Plugin
*/



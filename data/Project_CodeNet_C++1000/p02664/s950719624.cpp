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
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pcl pair<char, ll>
#define psl pair<string, ll>

ll N, M, A, B, C;
ll arr[MAX_INT], arr1[MAX_INT], data[MAX_INT];
vector<ll> V;
string S = "";

int main() {
	cin >> S;
	ll found = 0;
	fi(i, 0, S.size(), 1) {
		if(S[i] == 'P') {
			found = 1;
		}
		if(S[i] == '?') {
			// if(!found) {
			// 	S[i] = 'P';
			// 	found = 1;
			// }
			// else {
				S[i] = 'D';
			// }
		}
	}
	cout << S << "\n";

	return 0;
}
/*
	Powered by Buggy Plugin
*/



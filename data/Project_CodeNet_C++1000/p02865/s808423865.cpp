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
int main() {
	ios::sync_with_stdio(0);cout.precision(20);cout.tie(0);cin.tie(0);
	int n;
	cin >> n;
	cout << (n-1)/2 << '\n';
}


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef	long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef set<int> si;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef pair<ll, pll> plll;
typedef vector<pair<int, pii>> viii;
#define fi first
#define se second
#define pi 3.141592653589793
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define tc int tt;cin>>tt;while(tt--)
#define pqmax priority_queue<int>
#define pqmin priority_queue<int,vi,greater<int>>
#define fio ios_base::sync_with_stdio(0), cin.tie(NULL)
#define tc_g int tt;cin>>tt;for(int ti=1;ti<=tt;ti++)
#define case_g "Case #"<<ti<<": "
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
#define sleep for (int i = 1, a;i < 100000000;i++, a = a * a)
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ranked_pairset;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ranked_set;
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> ranked_map;

const int N = 1e6+1;

int main() {
	fio;
	vb p(N, 1);
	vi pf[N];
	for (int i = 2;i < N;i++)
		if (p[i])
			for (int j = i;j < N;j += i) {
				p[j] = 0;
				pf[j].pb(i);
			}
	int n;
	cin >> n;
	vb vis(N);
	int g = 0;
	bool pc = 1;
	for (int i = 0;i < n;i++) {
		int a;
		cin >> a;
		g = __gcd(g, a);
		for (auto x : pf[a])
			if (!vis[x])
				vis[x] = 1;
			else
				pc = 0;
	}
	if (pc)
		cout << "pairwise coprime\n";
	else if (g == 1)
		cout << "setwise coprime\n";
	else
		cout << "not coprime\n";
}

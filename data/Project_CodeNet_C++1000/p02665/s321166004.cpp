#define _CRT_SECURE_NO_DEPRECATE
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define int long long int
#define SYNC std::ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define FRE freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii>   vii;
//typedef tree<int, null_type, less<int>, rb_tree_tag, 
//             tree_order_statistics_node_update> 
//    data_set;
#define rep(i,l,r)   for(int i=(l);i<(r);i++)
#define deb(x)     cout << (#x) << " = " << (x) << endl
#define here cout << " Hey!!\n";
#define  pb push_back
#define  F  first
#define  S  second
#define all(v) (v).begin(),(v).end()
#define sz(a) (int)((a).size())
#define sq(x) ((x)*(x))
const int MOD = 1e9+7;
const int MOD1 = 998244353;
const int N = 2e5+5;
const int INF = 1000111000111000111LL;
const ld EPS = 1e-12;
const ld PI = 3.141592653589793116;

int32_t main()
{
	SYNC
	int n, rem, ans; cin >> n;
	vi d(n+1);
	for(auto &it : d)	cin >> it;
	vi node(n+1);
	node[0] = 1-d[0];
	rem = 1;
	rep(i,0,n+1) 
    {
        rem -= d[i];
        if (rem < 0) 
        {
            cout << -1 << '\n'; return 0;
        }
        rem *= 2; 
        if (rem > 1e15) rem = 1e15;
    }
	for(int i = 1; i <= n; i++) {
		node[i] = 2*node[i-1] - d[i];
		if(node[i] > 1e18)	{
			node[i] = 1e18;
		}
		if(node[i] < 0)	return cout << -1,0;
	}
	// for(auto it : node)	cout << it << ' ';
	// cout << endl;
	rem = 0, ans = 0;
	for(auto &it : d)	rem += it;
	for(int i = 0; i <= n; i++) {
		ans += min(node[i]+d[i],rem);
		rem -= d[i];
	}
	cout << ans;
	return 0;
}
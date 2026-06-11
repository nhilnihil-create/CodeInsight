#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define __FastIO                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);
#define D cout << "ok" << endl;
#define _(x) cout << #x << "->" << x;
#define _n cout<<endl;
#define __ cout<<" ";
#define ones(x) __builtin_popcount(x)
#define onesl(x) __builtin_popcountl(x)
#define onesll(x) __builtin_popcountll(x)
#define LOG2(x)                                                           \
  (sizeof(unsigned long) * 8 - 1 - __builtin_clzl((unsigned long)(x)))
#define LOG2_UP(x)                                                        \
  (((x) - (1 << FAST_LOG2(x))) ? FAST_LOG2(x) + 1 : FAST_LOG2(x))
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define FIN freopen("in", "r", stdin);
#define FOUT freopen("out", "w", stdout);
#define zero(b) memset(b,0,sizeof b);
#define mone(b) memset(b,-1,sizeof b);
#define gcd(a,b) __gcd(a,b)
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<db, db> pdd;
//template <typename T> using ordered_set = tree<T, null_type, less<T>,
//rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{
	__FastIO;
	int n,k;
	cin>>n>>k;
	if(k==1) 
	{
		cout<<0<<endl;
		return 0;
	}

	cout<<(n-k)<<endl;
}
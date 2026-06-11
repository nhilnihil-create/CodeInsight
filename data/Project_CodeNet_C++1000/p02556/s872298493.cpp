#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ull unsigned long long int
#define ll long long int
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define MOD (ull)(double)(1e9 + 7)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vb vector<bool>
#define vd vector<double>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>
#define pull pair<ull, ull>
#define F first
#define S second
#define m_p make_pair
#define debug(x) cout << #x << " " << x << endl
#define printArr(a, start, end)for(int i=start ; i<end ; ++i)cout << a[i] << " ";cout << '\n';
#define readArr(a, start, end)for(int i=start ; i<end ; ++i)cin >> a[i];
#define read2D(mat, n, m)for(int i=0 ; i<n ; ++i)for(int j=0 ; j<m ; ++j)cin >> mat[i][j];

const long double PI = 3.141592653589793238462643383279502884197169399;

// Find Set LSB = (x&(-x)), isPowerOfTwo = (x & (x-1))

void solve(){
	int n;
	cin >> n;
	
	vpll p(n);
	for(int i=0 ; i<n ; ++i){
		cin >> p[i].F >> p[i].S;
	}
	
	sort(all(p));
	
	ll ans=0;
	ll mx = p[0].S - p[0].F;
	ll mn = p[0].F + p[0].S;
	for(int i=1 ; i<n ; ++i){
		ans = max(ans, p[i].F - p[i].S + mx);
		ans = max(ans, p[i].F + p[i].S - mn);
		
		mx = max(mx, p[i].S - p[i].F);
		mn = min(mn, p[i].F + p[i].S);
	}
	
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << fixed << setprecision(10);
	
	int tt=1;
	//cin >> tt;
	
	while(tt--){
		solve();
	}
}

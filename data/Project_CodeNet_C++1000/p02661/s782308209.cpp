
// Problem : E - Count Median
// Contest : AtCoder - AtCoder Beginner Contest 169
// URL : https://atcoder.jp/contests/abc169/tasks/abc169_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define db double
#define mod 1000000007
#define pb push_back
#define pp pair<int,int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repe(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(int i=b;i>=a;i--)
#define maxn 200005
#define ss second
#define ff first
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
int inv(int a, int b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}
void solve()
{
	int n;
	cin >> n;
	int a[n],b[n];
	rep(i,0,n)
		cin >> a[i] >> b[i];
	sort(a,a+n);
	sort(b,b+n);
	int x=n/2;
	int r = b[n/2];
	int l = a[n/2];
	if(n%2 == 0)
	{
		r += (b[n/2-1]);
		l += (a[n/2-1]);
	}
	cout << r-l+1 <<"\n";
}
signed main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin >> t;
    while(t--)
    solve();
    return 0;
}

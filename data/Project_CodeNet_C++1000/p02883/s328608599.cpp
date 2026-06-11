
// Problem : E - Gluttony
// Contest : AtCoder - AtCoder Beginner Contest 144
// URL : https://atcoder.jp/contests/abc144/tasks/abc144_e
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
int n,k;
int a[maxn],f[maxn];
int check(int mid)
{
	int t =k;
	rep(i,0,n)
	{
		int x = a[i]*f[i];
		if(x > mid)
		{
			int r = mid/f[i];
			int diff = a[i]-r;
			if(diff > t)
			return false;
			t -= diff; 
		}
	}
	return true;
}
void solve()
{
	cin >> n >> k;	
	rep(i,0,n)
	cin >> a[i];
	rep(i,0,n)
	cin >> f[i];
	sort(a,a+n);
	sort(f,f+n,greater<int> ());
	int start = 0, end = (int)1e12,ans;
	while(start <= end)
	{
		int mid = (start+end)/2;
		if(check(mid))
		{
			ans = mid;
			end = mid-1;
		}
		else start= mid+1;
	}
	cout << ans;
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

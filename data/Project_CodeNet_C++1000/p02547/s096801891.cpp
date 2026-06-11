
// Problem : B - Go to Jail
// Contest : AtCoder - AtCoder Beginner Contest 179
// URL : https://atcoder.jp/contests/abc179/tasks/abc179_b
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
	int a[n] = {0},flag=0;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin >>x  >> y;
		if(x == y)
		{
			a[i]=1;
			if(i > 0)
				a[i] += a[i-1]; 
		}
		else a[i]=0;
		if(a[i] >= 3)
			flag=1;
	}	
	if(flag)
		cout << "Yes" <<"\n";
	else cout << "No" <<"\n";
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


// Problem : E - Divisible Substring
// Contest : AtCoder - AtCoder Beginner Contest 158
// URL : https://atcoder.jp/contests/abc158/tasks/abc158_e
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
int arr[maxn];
void solve()
{
	int t=1;
	int n,p;
	cin >> n >> p;
	string str;
	cin >> str;
	if(p==2 || p==5)
	{
		int cnt = 0;
		rep(i,0,n)
		if((str[i]-'0')%p==0)
		cnt+=(i+1);
		cout << cnt;
		return;
	}
	rep(i,0,n)
	{
		arr[i]=t;
		t*=10;
		t%=p;
	}
	int v[p]={0},prev=0;
	repr(i,0,n-1)
	{
		int x = str[i]-'0';
		x*=arr[n-1-i];
		x+=prev;
		x%=p;
		v[x]++;
		prev=x;
	}
	int ans = 0;
	rep(i,0,p)
	{
		//cout << v[i] <<"\n";
		if(i==0)
		{
			ans += ((v[i])*(v[i]+1))/2;
		}
		else ans += ((v[i]-1)*v[i])/2;
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

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define int long long
#define ll long long
#define vi vector <int>
#define vii vector <pair<int,int> >
#define rep(i,a,b) for (int i=a;i<b;i++)
#define repD(i,a,b) for (int i=a;i>b;i--)
#define pb push_back
#define pii pair <int,int>
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define MOD 1000000007
#define PI 3.14159265359
 
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
///*X.find_by_order("index")
///X.order_of_key("key")
 
#define deb(x) {x}
#ifndef local
	#define deb(x) ;
#endif
 
 
///----------------------------------------------------------------------------------

int n,k;
int arr[305];
int DP[305][305][305];

int fun(int cur, int rem, int prev)
{
	if (cur == n) return arr[prev];
	
	
	if (DP[cur][rem][prev] != -1) return DP[cur][rem][prev];
	
	int &res = DP[cur][rem][prev];
	
	///take 
	
	int take = fun(cur+1, rem, cur);
	if (prev != 303 && arr[cur] < arr[prev]) take += arr[prev] - arr[cur];
	
	int no = LLONG_MAX;
	if (rem)
		no = fun(cur+1, rem-1, prev);
	
	res = min(take, no);
	return res;
	
}

void solve()
{
	cin>>n>>k;
	rep(i,0,n)cin>>arr[i];
	memset(DP,-1,sizeof DP);
	cout<<fun(0,k,303);
	
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	
 	#ifdef local
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	clock_t qwertyuiop = clock();
	#endif
 
	int t=1;
	//cin>>t;
	
	rep(a,0,t)
	{
		//cout<<"Case #"<<a+1<<": ";
		solve();

	}
	
	#ifdef local
	{qwertyuiop = clock() - qwertyuiop;double time_taken = ((double)qwertyuiop)/CLOCKS_PER_SEC;cerr<<fixed<<setprecision(5)<<"\n\nTime Taken : "<<time_taken<<" seconds\n";}
	#endif
}
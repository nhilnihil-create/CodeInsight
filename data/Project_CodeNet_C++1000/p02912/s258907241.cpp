//----------BHAVIK DIWANI(PICT_COMP)---------------
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define test ll t; cin>>t; while(t--)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define ll long long
#define int long long
#define ull unsigned long long
#define MAX 1005
#define pb push_back
#define mkp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define endl '\n'
#define vs vector<string>
#define mii map<int,int>
#define msi map<string,int>
#define vpii vector< pair<int, int > >
#define vpsi vector< pair< string ,int > >
#define forci(p,q) for(int i=p;i<q;i++)
using namespace std;

int solve()
{
	int n,m;
	cin>>n>>m;
	int a[n];
	priority_queue<int> q;
	for(int i=0;i<n;i++){
		cin>>a[i];
		q.push(a[i]);
	}
	for(int i=0;i<m;i++){
		int x=q.top();
		q.pop();
		x/=2;
		q.push(x);
	}
	int ans=0;
	while(!q.empty()){
		int x=q.top();
		ans+=x;
		q.pop();
	}
	cout<<ans<<endl;
	
	return 0;
}
signed main()
{
	fastio;
//	test
		solve();
}
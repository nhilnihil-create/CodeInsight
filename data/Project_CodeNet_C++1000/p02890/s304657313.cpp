#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (int i = k; i <= n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define pb push_back
#define F first
#define S second
#define I insert
#define mp make_pair
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define debug1(a) cout<<" "<<#a<<" : "<<a<<"\n"
#define debug2(a,b) cout<<" "<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<"\n"
#define debug3(a,b,c) cout<<" "<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<"\n"
#define debug4(a,b,c,d) cout<<" "<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<"\n"
// #define M 421412341324321
#define MOD 998244353

signed main()
{
	// ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int n;
	cin>>n;
	int a[n];
	int cnt[n+1]={0};
	rep(i,n)
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	vector <int> v;
	REP(i,1,n)
	{
		if (cnt[i]>0)
		{
			v.pb(cnt[i]);
		}
	}
	sort(all(v));
	vector <int> pre(sz(v)+1,0);

	rep(i,sz(v))
	{
		pre[i+1]=pre[i]+v[i];
	}

	REP(k,1,n)
	{
		int l =0, h = n/k;
		while(l<h)
		{
			int m = (l+h+1)/2;
			int t = 0;
			int x = lower_bound(all(v),m) - v.begin();
			t+=sz(v)-x + pre[x]/m;
			if (t>=k) l = m;
			else h = m-1;
		}
		cout<<l<<"\n";
	}

}

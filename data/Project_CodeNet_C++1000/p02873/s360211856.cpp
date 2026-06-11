#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
#define MOD (ll)(1e9+7)
#define INF INT32_MAX
#define INFL INT64_MAX
using namespace std;

void solve()	{
	string s;
	cin >> s;
	int n = s.size();
	ll a[n+1];
	memset(a,-1,sizeof(a));
	for(int i=0; i<n; i++)	{
		if(i==0 && s[i]=='<')	a[i]=0;
		else {
			if(s[i]=='<' && s[i-1]=='>')	a[i]=0;
			if(s[i]=='<' && s[i-1]=='<')	a[i]=a[i-1]+1;
		}
	}
	if(s[n-1]=='<')	a[n]=a[n-1]+1;
	else a[n]=0;
	for(int i=n-1; i>=0; i--)	{
		if(i-1 >=0 && s[i]=='>' && s[i-1]=='<')	a[i]=max(a[i-1],a[i+1])+1;
		else if(s[i]=='>') a[i]=a[i+1]+1;
	}
	ll ans=0;
	for(int i=0; i<=n; i++)	ans+=a[i];
	cout << ans << endl;
}

int main()	
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin >> t;
	for(int i=1; i<=t; i++)	{
		solve();
	}
	return 0;
}
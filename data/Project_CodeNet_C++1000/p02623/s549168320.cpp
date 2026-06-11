#include <bits/stdc++.h> 
using namespace std;

signed main()
{
	ios::sync_with_stdio(0);
	long long n,m,k,ans=0;
    cin >> n >> m >> k;
    
    long long a[n+5]={0};
	long long b[m+5]={0};
	
    for(long long i=1; i<=n; i++)
    {
    	cin >> a[i];
		a[i] += a[i-1];
    }
    for(long long i=1; i<=m; i++)
    {
    	cin >> b[i];
		b[i] += b[i-1];
    }
    
    for(long long i=0; i<=n; i++) 
    { 
		if(k>=a[i])
		{ 
			ans = max(ans,upper_bound(b+1,b+1+m,k-a[i])-b-1+i);
		} 
	} 
    
	cout << ans << endl;
	return 0;
} 
	#include<bits/stdc++.h>
	using namespace std; 
	#define max(a, b) (a < b ? b : a) 
	#define min(a, b) ((a > b) ? b : a) 
	#define mod 1e9 + 7 
	#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
	#define FORL(a, b, c) for (int(a) = (b); (a) < (c); (a)++) 
	#define FORR(a, b, c) for (int(a) = (b); (a) > (c); (a)--) 
	#define INF 1000000000000000003 
	typedef long long int ll; 
	typedef vector<int> vi; 
	typedef vector<long long int> vl; 
	typedef pair<int, int> pi; 
	typedef pair<long long int, long long int> pl; 
	#define F first 
	#define S second 
	#define pb push_back 
	#define POB pop_back 
	#define mp make_pair 
	

	int main()
	 {ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
		ll n,c;
		cin>>n;
		vl dp(n);
		dp[0]=0;
		dp[1]=1;
		if(n>2)
		{for(int i=2;i<n;i++)
		{	c=0;
			for(int j=1;j<=sqrt(i);j++)
			{
				if(i%j==0 && j!=(i/j))
				c+=2;
				if(i%j==0 && j==(i/j))
				c+=1;
			}
			dp[i]=dp[i-1]+c;
		}}
		cout<<dp[n-1];

		
	return 0;
	}

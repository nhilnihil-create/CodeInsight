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
		ll n,x,y;
		//vector<pl>a(n);
		cin>>n;
		int m=0,c=0;
		FOR(i,n)
		{
			cin>>x>>y;
			if(x==y)
			c++;
			else
			{
				m=max(m,c);
				c=0;
		}}
		m=max(m,c);
			if(m>=3)
			cout<<"Yes"<<endl;
			else
			{
				cout<<"No"<<endl;
			}
		
		
	

		
	return 0;
	}





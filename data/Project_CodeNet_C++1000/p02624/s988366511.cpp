#if __has_include("debug.h")
    #include "debug.h"
#else  
#include <bits/stdc++.h>
using namespace std;
#define d(...) 2;
#endif

#define int long long int

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"      

#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define ff first
#define ss second
#define eps 1e-10

#define gcd(a,b)            __gcd((a),(b))
#define lcm(a,b)            ((a*b)/gcd(a,b))

void solve();

const int N=1e7+1;

vector<int>divisor(N);

void init()
{
	int i,j;
	for(i=1;i<=N;i++)
	{
		for(j=i;j<=N;j+=i)
		{
			divisor[j]++;
		}
	}
}

int32_t main()
{
    #ifdef DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    #endif 

    fast
    
    int t = 1;
	// cin>>t;
	
	while(t--)
	    solve();
	return 0;  
}

void solve()
{
	int i,j;
	int n;
	cin>>n;

	init();

	int sum=0;

	for(i=1;i<=n;i++)
	{
		sum+=i*divisor[i];
	}

	cout<<sum<<endl;

}
#if __has_include("debug.h")
    #include "debug.h"
#else  
#include <bits/stdc++.h>
using namespace std;
#define d(...) 2;
#endif

#define int long long int
#define ld long double

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"      

#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define ff first
#define ss second
#define eps 1e-10
#define PI acos(-1LL)

#define gcd(a,b)            __gcd((a),(b))
#define lcm(a,b)            ((a*b)/gcd(a,b))

void solve();

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
	int n,m;
	cin>>n>>m;

	vector<int>a(n);

	for(i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]/=2;
	}

	int lc=1;

	for(i=0;i<n;i++)
	{
		lc=lcm(lc,a[i]);
	}

	 int flag=0;
    for(int i=0;i<n;i++){
        int temp=(lc)/a[i];
        if(temp%2==0){
            flag=1;
            break;
        }
    }


	d(lc);

	if(flag)
	{
		cout<<0<<endl;
		return ;
	}

	int multi=m/lc;

	d(multi);

	multi=ceil(multi/(long double)2);

	cout<<multi<<endl;

}
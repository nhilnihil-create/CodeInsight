#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long 
#define mp make_pair
#define pb push_back
#define gcd(a, b)   __gcd(a, b)
#define lcm(a, b)  ((a)*((b)/gcd(a,b)))
#define pi 3.14159265358979323846
#define reus ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int32_t main()
{
	reus;

//	#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	#endif
    
    int n;
    cin>>n;
    int a[n+5];
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	int c=0;
	for(int i=1;i<=n;i+=2)
	{
		if(a[i]&1)
		c++;
	}
	cout<<c<<endl;
	
	return 0;
}
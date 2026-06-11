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
    
    int a,b,c,x,R=0,G=0,B=0;
    cin>>a>>b>>c>>x;
    bool f=false;
    for(int i=0;i<=x;i++)
    {
    	for(int j=0;j<=x;j++)
    	{
    		for(int k=0;k<=x;k++)
    		{
    			B=c*(1<<k);
    			G=b*(1<<j);
    			R=a*(1<<i);
    			if(B>G&&G>R &&(i+j+k<=x))
    			f=true;
			}
		}
	}
    if(f==true)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
	return 0;
}
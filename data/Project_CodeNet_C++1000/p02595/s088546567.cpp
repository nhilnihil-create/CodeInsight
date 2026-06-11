#include<bits/stdc++.h>
using namespace std;
#define FOR(x,i,e) for(int x=i; x<e; x++)
#define int long long int
 
signed main()
{
	int n,d;
	cin>>n>>d;
	int x[n],y[n];
    int c=0;
	FOR(i,0,n)
	{
		cin>>x[i]>>y[i];
        if ((x[i]*x[i]+y[i]*y[i])<=(d*d)) c++;
	}
    cout<<c<<endl;
	return 0;
}
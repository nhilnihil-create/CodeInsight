#include <bits/stdc++.h>
using namespace std;

int main() {
	long long i,j,r,g,b,k;
	cin>>r>>g>>b;
	cin>>k;
	int k1=0;
	while(g<=r)
	{
	    g*=2;
	    k1++;
	}
	if(k1>k)
	
	{
	    cout<<"No";
	    return 0;
	}
	while(b<=g)
	{
	    b*=2;
	    k1++;
	}
	if(k1>k)
	
	{
	    cout<<"No";
	    return 0;
	}
	cout<<"Yes";
	
	
}

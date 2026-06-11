#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int X;
	cin>>X;
	int t=360;
	while(t%X!=0)
	{
		t+=360;
	}
	cout<<t/X<<endl;
	return 0;
}

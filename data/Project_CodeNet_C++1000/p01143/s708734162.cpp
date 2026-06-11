#include<bits/stdc++.h>
using namespace std;

main(int argc, char const *argv[])
{
	int n,m,p;
	while(cin>>n>>m>>p,n)
	{
		int x,s=0,w;
		for (int i = 0; i < n; ++i)
		{
			cin>>x;
			s+=x;
			if(i==m-1) w=x;
		}
		s*=100;
		if(w>0)	cout<<s*(100-p)/100/w<<endl;
		else cout<<"0\n";
	}
	return 0;
}

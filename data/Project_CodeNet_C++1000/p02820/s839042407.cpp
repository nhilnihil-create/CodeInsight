#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N,K;
	cin>>N>>K;
	ll R,S,P;
	cin>>R>>S>>P;
	string T;
	cin>>T;
	string prev="";
	ll ans=0;
	rep(i,K)
	{
		switch(T[i])
		{
			case 'r':
				prev+='p';
				ans+=P;
				break;
			case 's':
				prev+='r';
				ans+=R;
				break;
			case 'p':
				prev+='s';
				ans+=S;
				break;
			default:
				break;
		}
	}
	for(int i=K;i<N;i+=K)
	{
		for(int k=i;k<min(i+K,N);k++)
		{		
			switch(T[k])
			{
				case 'r':
					if(prev[(k%K)]=='p')
					{
						prev[(k%K)]='o';
					}
					else
					{
						prev[(k%K)]='p';
						ans+=P;
					}
					break;
				case 's':
					if(prev[(k%K)]=='r')
					{
						prev[(k%K)]='o';
					}
					else
					{
						prev[(k%K)]='r';
						ans+=R;
					}
					break;
				case 'p':
					if(prev[(k%K)]=='s')
					{
						prev[(k%K)]='o';
					}
					else
					{
						prev[(k%K)]='s';
						ans+=S;
					}
					break;
				default:
					break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

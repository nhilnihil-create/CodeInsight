#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N;
	cin>>N;
	vector<int> L(N);
	rep(i,N)
	{
		cin>>L[i];
	}
	sort(L.begin(),L.end());
	ll ans=0;
	rep(i,N-1)
	{
		int a=L[i];
		Rep(j,i+1,N)
		{
			int b=L[j];
			int head=j;
			int tail=N;
			while(tail-head>1)
			{
				int mid=head+(tail-head)/2;
				int c=L[mid];
				if(c<a+b)
				{
					head=mid;
				}
				else
				{
					tail=mid;
				}
			}
			ans+=head-j;
		}
	}
	cout<<ans<<endl;
	return 0;
}

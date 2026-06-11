#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N;
	cin>>N;
	vector<int> X(N);
	rep(i,N) cin>>X[i];
	ll ans=1e9;
	Rep(x,1,101)
	{
		ll v=0;
		rep(j,N)
		{
			v+=(ll)pow((X[j]-x),2.0);
		}
		ans=min(ans,v);
	}
	cout<<ans<<endl;
	return 0;
}

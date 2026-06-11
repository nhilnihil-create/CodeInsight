#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N,K;
	cin>>N>>K;
	vector<ll> H(N);
	rep(i,N) cin>>H[i];
	sort(H.begin(),H.end(),greater<ll>());
	ll ans=0;
	Rep(i,K,N)
	{
		ans+=H[i];
	}
	cout<<ans<<endl;
	return 0;
}

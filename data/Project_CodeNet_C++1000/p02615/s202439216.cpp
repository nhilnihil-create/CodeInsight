#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N;
	cin>>N;
	vector<ll> A(N);
	rep(i,N) cin>>A[i];
	sort(A.begin(),A.end(),greater<ll>());
	ll ans=A[0];
	int k=1;
	for(int i=0;i<N-2;i++)
	{
		ans+=A[k];
		if(i%2==1) k++;
	}
	cout<<ans<<endl;
	return 0;
}

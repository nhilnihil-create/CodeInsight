#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int K,N;
	cin>>K>>N;
	vector<ll> A(N);
	rep(i,N)
	{
		cin>>A[i];
	}
	ll mx=0;
	rep(i,N-1)
	{
		mx=max(mx,A[i+1]-A[i]);
	}
	mx=max(mx,K-A[N-1]+A[0]);
	ll sum=K;
	cout<<sum-mx<<endl;
	return 0;
}

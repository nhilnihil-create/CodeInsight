#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


bool f(ll x,ll K,ll N,vector<ll> A,vector<ll> F)
{
	ll res=0;
	rep(i,N)
	{
		res+=max(A[i]-x/F[i],(ll)0);
	}
	return res<=K;
}
int main()
{
	ll N,K;
	cin>>N>>K;
	vector<ll> A(N);
	rep(i,N) cin>>A[i];
	vector<ll> F(N);
	rep(i,N) cin>>F[i];
	sort(A.begin(),A.end());
	sort(F.begin(),F.end(),greater<ll>());
	ll head=-1;
	ll tail=A[N-1]*F[0];
	while(tail-head>1)
	{
		ll mid=head+(tail-head)/2;
		if(f(mid,K,N,A,F))
		{
			tail=mid;
		}
		else
		{
			head=mid;
		}
	}
	cout<<tail<<endl;
	return 0;
}

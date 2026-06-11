#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N;
	cin>>N;
	map<int,ll> m;
	vector<int> A(N);
	rep(i,N)
	{
		cin>>A[i];
		m[A[i]]++;
	}
	ll ans=0;
	for(auto p : m)
	{
		ans+=p.second*(p.second-1)/2;
	}
	for(int a : A)
	{
		ll v=m[a];
		cout<<ans-(v*(v-1)/2-(v-1)*(v-2)/2)<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N;
	cin>>N;
	vector<int> ans(N);
	rep(i,N)
	{
		int a;
		cin>>a;
		ans[a-1]=i+1;
	}
	rep(i,N)
	{
		cout<<ans[i];
		if(i!=N-1) cout<<" ";
	}
	cout<<endl;
	return 0;
}

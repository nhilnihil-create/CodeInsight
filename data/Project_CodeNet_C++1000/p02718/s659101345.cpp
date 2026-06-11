#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N,M;
	cin>>N>>M;
	vector<int> A(N);
	int sum=0;
	rep(i,N)
	{
		cin>>A[i];
		sum+=A[i];
	}
	int cnt=0;
	rep(i,N)
	{
		if(A[i]>=(sum+(4*M)-1)/(4*M)) cnt++;
	}
	if(cnt>=M)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}

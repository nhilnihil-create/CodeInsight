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
	vector<ll> B(N);
	rep(i,N)
	{
		cin>>A[i]>>B[i];
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	if(N%2==0)
	{
		cout<<(B[N/2-1]+B[N/2])-(A[N/2-1]+A[N/2])+1<<endl;
	}
	else
	{
		cout<<B[N/2]-A[N/2]+1<<endl;
	}
	return 0;
}

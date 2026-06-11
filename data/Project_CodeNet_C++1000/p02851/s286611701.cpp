#include<iostream>
#include<map>
using namespace std;
int N,K;
int A[2<<17];
long tmp[2<<17];
main()
{
	cin>>N>>K;
	map<long,int>M;
	long ans=0,cumsum=0;
	M[0]=1;
	for(int i=0;i<N;i++)
	{
		if(i>=K-1)M[tmp[i+1-K]]--;
		cin>>A[i];
		tmp[i+1]=(cumsum+=A[i]-1)%=K;
		ans+=M[cumsum]++;
	}
	cout<<ans<<endl;
}

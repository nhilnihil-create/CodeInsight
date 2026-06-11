#include<bits/stdc++.h>
using namespace std;
long long A[200100],B[200100];
int N;
long long K;
bool Check(long long X)
{
	long long Sum=0;
	for(int i=0;i<N;i++)
	{
		int Y=min(X/B[i],A[i]);
		Sum+=A[i]-Y;
	}
	if(Sum<=K)
		return true;
	return false;
}
int main()
{
	cin>>N>>K;
	for(int i=0;i<N;i++)
		cin>>A[i];
	for(int i=0;i<N;i++)
		cin>>B[i];
	sort(A,A+N);
	sort(B,B+N);
	reverse(B,B+N);
	long long L=0,R=1000000000000000000;
	while(L<R)
	{
		long long mid=(L+R)/2ll;
		if(Check(mid))
			R=mid;
		else	L=mid+1;
	}
	cout<<L<<endl;
	return 0;
}
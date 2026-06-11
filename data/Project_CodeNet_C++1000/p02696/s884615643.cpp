#include <iostream>
using namespace std;
int main()
{
	long long int N,M,K,X,sum=0;
	cin>>N>>M>>K;
	
	if((M==1)||(K==1))
	X=1;
	else if(M<=K)
	X=M-1;
	else
	X=K;
	
	
	sum=(long long int)((N*X)/M)-N*(long long int)(X/M);
	cout<<sum;
	return 0;
}
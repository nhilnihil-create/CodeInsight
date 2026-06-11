#include<iostream>

using namespace std;

int main() 
{
	long long N,X,T;cin>>N>>X>>T;
	int sum_X=0;
	int sum_T=0;
	while(sum_X<N){
		sum_X+=X;
		sum_T+=T;
	}
	
	cout<<sum_T;
	return 0;
}
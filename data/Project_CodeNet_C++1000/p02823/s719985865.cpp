#include <bits/stdc++.h>
using namespace std;

int main(){

	long long int N;
	long long int A,B;

	cin>>N>>A>>B;
	long long int diff=B-A;
	if(diff%2==0)
	{
		cout<<diff/2<<endl;
	}
	else
	{
		long long int S1,E1;
		S1=A-1;
		E1=N-B;
		if(S1>E1)
		{
			cout<<E1+1+(B-A-1)/2<<endl;
		}
		else
		{
			cout<<S1+1+(B-A-1)/2<<endl;
		}
	}



	return 0;
}
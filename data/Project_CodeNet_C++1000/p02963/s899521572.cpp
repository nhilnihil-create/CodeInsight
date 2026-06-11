#include<iostream>
#include<cmath>
using namespace std;
long S;
main()
{
	cin>>S;
	long L=sqrt(S);
	while(L*L<S)L++;
	cout<<"0 0 "<<L<<" 1 "<<L*L-S<<" "<<L<<endl;
}

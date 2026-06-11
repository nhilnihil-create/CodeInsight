#include<iostream>
using namespace std;
main()
{
	string S,T,U;
	int A,B;
	cin>>S>>T>>A>>B>>U;
	if(S==U)
	{
		A--;
	}
	else if(U==T)
	{
		B--;
	}
	cout<<A<<" "<<B<<endl;
}

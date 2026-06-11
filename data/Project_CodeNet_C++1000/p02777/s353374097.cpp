#include<bits/stdc++.h>
using namespace std;
int main()
{
	int A,B;
	string S,T,U;
	cin>>S>>T>>A>>B>>U;
	if(S==U){
		cout<<A-1<<" "<<B;
	}
	else{
		cout<<A<<' '<<B-1;
	}
	return 0;
 } 
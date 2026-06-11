#include<bits/stdc++.h>
using namespace std;
int main()
{
	int A,B,C;
	cin>>A>>B>>C; 
	if(A==B&&B==C){
		cout<<"No";
	}
	else if(A!=B&&B!=C&&A!=C){
		cout<<"No";
	}
	else{
		cout<<"Yes";
	}
	return 0;
}
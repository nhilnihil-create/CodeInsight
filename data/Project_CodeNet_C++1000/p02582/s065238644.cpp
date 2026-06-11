#include<bits/stdc++.h>
using namespace std;
int main()
{
	string A;
	cin>>A;
	if(A=="RRR"){
			cout<<3;
		}	
	else if(A=="SSS"){
		cout<<0;
	}
	else if(A=="SRR"||A=="RRS"){
		cout<<2;
	} 
	else if(A=="SRS"||A=="RSS"||A=="SSR"||A=="RSR"){
		cout<<1;
	}
	return 0;
}
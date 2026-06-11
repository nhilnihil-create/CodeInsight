#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 0;i<n;i++)



int main(){

	int n;
	cin>>n;

	bool present = false;

	while(n!=0){
		if(n%10==7){
			present = true;
			break;
		}
		n=n/10;
	}

	if(present){
		cout<<"Yes";
	}
	else cout<<"No";
	
}
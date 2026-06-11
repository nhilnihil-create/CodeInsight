#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,c=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		if(i&1){
			c++;
		}
	}
	double ans=(double)c/n;
	cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	int a=7;
	for(int i=1;i<=n;i++){
		if(a%n==0)
		{
		cout<<i;	
	 return 0;
		}
		else
		a=(a*10+7)%n;
	}
	cout<<"-1";
}
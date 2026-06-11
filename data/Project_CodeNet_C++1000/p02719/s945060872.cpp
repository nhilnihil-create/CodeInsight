#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,k,x;
	cin>>n>>k;
	x=n%k;	
	cout<<min(x,abs(x-k))<<endl;
	return 0;
}
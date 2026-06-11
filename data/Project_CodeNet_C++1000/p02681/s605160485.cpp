#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
	string s,t,n;
	int i,j;
	cin>>s>>t;
	i=s.length(); j=t.length();
	n=t.substr(0,j-1);
	if(s==n)
	std::cout << "Yes" << std::endl;
	else
	cout<<"No"<<endl;
	
	return 0;
}
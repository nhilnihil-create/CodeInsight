#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string s;
	cin>>n;
	cin>>s;
	if(n<s.size()){
		cout<<s.substr(0,n)<<"...";
	}
	else{
		cout<<s.substr(0,n);
	}
	return 0;
}
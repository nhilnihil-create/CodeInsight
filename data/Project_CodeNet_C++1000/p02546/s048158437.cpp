#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int main() {
	// your code goes here
	string str;
	cin>>str;
	int l=str.length();
	if(str[l-1]=='s')
	str+="es";
	else
	str+='s';
	cout<<str<<"\n";
	return 0;
}
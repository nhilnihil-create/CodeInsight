#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	if(s[s.length()-1]=='s') s=s+'e';

	cout<<s+'s';
	return 0;
}
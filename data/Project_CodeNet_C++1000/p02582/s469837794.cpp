
#include<iostream>
#include<string>
using namespace std;
int main(){
string s;
cin>>s;
if(s=="RRS"||s=="SRR")
	cout<<"2";
else if(s=="SSS")
	cout<<"0";
else if(s=="RSR"||s=="RSS"||s=="SSR"||s=="SRS")
	cout<<"1";
else
	cout<<"3";






}

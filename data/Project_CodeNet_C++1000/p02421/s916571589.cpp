#include <iostream>
using namespace std;

int main() {
	int n;cin>>n;
	string t,h;
	int ct=0,ch=0;
	for(int i=0;i<n;i++)
	{
		cin>>t>>h;
		if(t==h)ct++,ch++;
		else if(t<h)ch+=3;
		else ct+=3;
	}
	cout<<ct<<" "<<ch<<endl;
	return 0;
}
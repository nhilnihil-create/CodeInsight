#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	if(s.at(0) == s.at(1) || s.at(1) == s.at(2)|| s.at(2) == s.at(3))
	{ cout<<"Bad"<<"\n"; }
	else	{ cout<<"Good"<<"\n"; }

	return 0;
}
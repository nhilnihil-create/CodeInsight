#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s, t;
	int c = 0;
	cin>>s>>t;
	for(int x = 0; x < s.length(); x++){
		if(s[x] != t[x])
			++c;
	}
	cout<<c<<endl;
	return 0;
}


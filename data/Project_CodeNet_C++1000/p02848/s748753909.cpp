#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	int x;
	cin>>x; cin>>s;
	for (auto a: s)
	{
		a+=x;
		if (a>90)
			a-=26;
		cout<<a;
	}
	cout<<endl;
	return 0;
}
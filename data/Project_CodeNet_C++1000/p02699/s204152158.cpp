#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a, b;
	cin>>a>>b;
	if(b >= a)
		cout<<"unsafe"<<endl;
	else
		cout<<"safe"<<endl;
	return 0;
}
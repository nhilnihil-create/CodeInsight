#include <bits/stdc++.h>
using namespace std;


#define endl "\n"
#define Yes() cout << "Yes" << endl
#define No() cout << "No" << endl


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string sh; cin>>sh;
	if (sh == "Sunny")
	{
		cout<<"Cloudy"<<endl;
	}
	else if (sh == "Cloudy")
	{
		cout<<"Rainy"<<endl;
	}
	else
		cout<<"Sunny"<<endl;
	return 0;

}
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<char> v;
	for (int i = 0; i < n; ++i)
	{
		char x;
		cin >> x;
		v.push_back(x);
	}
	if(n%2!=0){
			cout << "No" << endl;
			exit(0);
		}
	int l = n*0.5;
	for (int i = 0; i < l; ++i)
	{
		if(v[i] != v[i+l]){
			cout << "No" << endl;
			exit(0);
		}
	}
	cout << "Yes" << endl;

	return 0;
}
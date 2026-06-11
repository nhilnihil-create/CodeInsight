#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int n = s.size();
	for(int i = 0; i < n; i += 2)
	{
		if(s[i] == 'L')
			return cout << "No" << endl , 0;
	}

	for(int i = 1; i < n; i += 2)
	{
		if(s[i] == 'R')
			return cout << "No" << endl , 0;
	}

	cout << "Yes" << endl;
}










 

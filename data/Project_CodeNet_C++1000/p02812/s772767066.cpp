#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n; cin >> n;
	string s; cin >> s;
	int c = 0;
	for (int i = 0; i < n; ++i)
		if (s[i] == 'A')
			if (i + 1 < n && s[i+1] == 'B')
				if (i + 2 < n && s[i+2] == 'C')
					c++, i+=2;
	cout << c << endl;
}


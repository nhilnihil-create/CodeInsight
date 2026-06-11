#include <bits/stdc++.h>

using namespace std;


int main()
{

	string s , t;
	cin >> s >> t;
	int cnt = 0 , c = 0;

	for(int i = 0 ;i <= s.size()-t.size();i++)
	{
		for(int j = 0;j < t.size();j++)
			if(s[i + j] == t[j])
				cnt++;

	c = max(c,cnt);
	cnt = 0;
	}
	cout << t.size() - c;
}
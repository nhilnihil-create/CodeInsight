#include <bits/stdc++.h>
#include <vector>

#define fo(i, t) for(int i = 0; i < t; i++)
#define rfo(i, t) for(int i = n - 1; i > 0; i--)
#define pb push_back

/*typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
typedef vector<vector<int>> mi;*/

using namespace std;

int main()
{
	int t = 1;
	string s;	
	for(int i = 0; i < t; i++)
	{
		cin >> s;
		if(s[s.length() - 1] != 's')
			s.push_back('s');
		else
		{
			s.push_back('e');
			s.push_back('s');	
		}
	}
	cout << s;
}
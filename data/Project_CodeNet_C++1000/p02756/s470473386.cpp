#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int, int>
#define dd pair<double, double>
#define pb(i) push_back(i)
const double PI = 3.14159265359;
const int inf = 1e9+77;
const ll mod = 1e9+7;
const double eps = 1e-7;
//int dir1[8] = {0, 0, 1, -1, 1, -1, 1, -1};
//int dir2[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dir1[4] = {0, 0, 1, -1};
int dir2[4] = {1, -1, 0, 0};

int main()
{
	int i, j;

	int ind = 0;
	string s[2], mid;
	cin >> mid;
	s[0] = "", s[1] = "";

	int q; cin >> q;
	while(q--)
	{
		int a, b;
		char c;
		
		cin >> a;
		if(a == 1)
			ind = (ind+1)%2;
		else
		{
			cin >> b >> c;
			if(b == 1)
				s[ind] += c;
			else
				s[(ind+1)%2] += c;
		}
	}

	for(i = s[ind].size()-1; i > -1; i--)
		cout << s[ind][i];
	
	if(ind == 0)
		cout << mid;
	else
		for(i = mid.size()-1; i > -1; i--)
			cout << mid[i];
	
	cout << s[(ind+1)%2] << '\n';

}
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);cin.tie(0);
#define mod 1000000007
#define pi 2*acos(0)
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
using namespace std;



int main()
{

	io;
	
	string s, t; cin >> s >> t;
	int del = 0;
	int ans = INT_MAX;

	for (int i = 0; i <= s.size() - t.size(); i++) {
		int k = i;



		for (int j = 0; j < t.size(); j++) {
			
			if (t[j] != s[k]) del++;
			k++;
		}
		ans = min(ans, del);
		del = 0;

	}
	


	cout << ans;

}


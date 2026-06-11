#include<bits/stdc++.h>

using namespace std;


int main()
{
	string s; cin >> s;
	int v = 2019 , pow = 1, val = 0;
	int n = s.size();
	map<int,int> m;
	int ans = 0;
	m[0]++;
	for(int i = n-1; ~i; i--){
		int k = s[i]-'0';
		val = (val+(k*pow))%2019;
		ans += m[val];
		m[val]++;
		pow = pow*10%2019;
	}
	cout << ans;
}

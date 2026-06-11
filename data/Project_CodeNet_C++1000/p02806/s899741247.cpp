#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 110;
int n;
string s[MAX_N], x;
int t[MAX_N];

void solve()
{
	int ans = 0;
	bool seen = false;
	for(int i=0;i<n;++i){
		if(s[i] == x) seen = true;
		else if(seen) ans+=t[i];
	}
	cout<<ans;
}

int main()
{
	cin >> n;
	for(int i=0;i<n;++i) cin >> s[i] >> t[i]; 
	cin >> x;
	solve();
	return 0;
}
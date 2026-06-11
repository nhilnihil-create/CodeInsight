#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 5e6+10;
string s;
int le[MAX_N], ri[MAX_N];

void solve()
{
	const int n = s.length();
	for(int i=0;i<n;++i){
		if(s[i] == '<') le[i+1]=max(le[i+1], le[i]+1);
		else le[i+1] = 0;
	}
	for(int i=n-1;i>=0;--i){
		if(s[i] == '>') ri[i]=max(ri[i],ri[i+1]+1);
		else ri[i] = 0;
	}
	ll ans = 0;
	for(int i=0;i<=n;++i) ans+=max(le[i],ri[i]);
	cout<<ans;
}

int main()
{
	cin >> s;
	solve();
	return 0;
}
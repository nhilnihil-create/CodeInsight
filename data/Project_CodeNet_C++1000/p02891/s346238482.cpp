#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
int k;

void solve()
{
	const int n = s.length();
	if(s == string(n, s[0])){
		cout << 1LL*n*k/2 << '\n';
	}else{
		int cnt = 1;
		ll ans = 0;
		for(int i=1;i<n;++i){
			if(s[i]==s[i-1])cnt++;
			else{
				ans += cnt/2;
				cnt = 1;
			}
		}
		ans += cnt/2;
		if(s[0]!=s[n-1]){
			cout << 1LL*k*ans << '\n';
		}else{
			int a=1,b=1;
			int i=1,j=n-2;
			while(s[i]==s[0])a++,i++;
			while(s[j]==s[n-1])b++,j--;
			cout << 1LL*ans*k - 1LL*(k-1)*(a/2+b/2-(a+b)/2) << '\n';
		}
	}
}

int main()
{
	cin >> s >> k;
	solve();
	return 0;
}
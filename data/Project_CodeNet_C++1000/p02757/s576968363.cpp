#include<bits/stdc++.h>
using namespace std;
#define int long long
int n , mod , now , ans , base = 1;
string s;
map<int , int>vis;
signed main()
{
	cin >> n >> mod >> s ;
	if(mod == 2 || mod == 5)
	{
		for(int i = 0 ; i < n ; i ++)
		{
			int x = s[i] - '0';
			if(x % mod == 0) ans += i + 1 ;
		}
		return cout << ans << '\n' , 0;
	}
	reverse(s.begin() , s.end()) , vis[0] = 1;	
	for(auto i : s)
	{
		int x = i - '0';
		now = (now + x * base) % mod;
		ans += vis[now]; 
		vis[now] ++ , base *= 10 , base %= mod;
	}
	cout << ans << '\n';
	return 0;
}
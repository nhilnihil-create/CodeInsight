#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll ans[1000010][13];
int main() {
	string s;
	cin>>s;
	if(s[0]=='?'){
		for(ll i=0;i<10;i++){
			ans[0][i]=1;
		}
	}
	else{
		ll now=s[0]-'0';
		ans[0][now]=1;
	}
	for(ll i=1;i<s.size();i++){
		if(s[i]=='?'){
			for(ll j=0;j<10;j++){
				for(ll k=0;k<13;k++){
					ll next=(k*10+j)%13;
					ans[i][next]+=ans[i-1][k];
					ans[i][next]%=inf;
				}
			}
		}
		else{
			ll now=s[i]-'0';
			for(ll k=0;k<13;k++){
				ll next=(k*10+now)%13;
				ans[i][next]+=ans[i-1][k];
				ans[i][next]%=inf;
			}
		}
	}
	cout << ans[s.size()-1][5];
	return 0;
}
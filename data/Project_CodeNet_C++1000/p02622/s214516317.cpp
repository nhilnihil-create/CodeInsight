#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t = 1;
	// cin>>t;

	while(t--){
		
		string s,r;
		cin>>s>>r;

		ll ans = 0;
		for(ll i=0;i<s.length();++i) if(s[i] != r[i]) ++ans;

		cout<<ans<<"\n";

	}

	return 0;

}
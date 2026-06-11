#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string s,t;
	ll ans=0;
	cin >> s >> t;
	for(ll i=0;i<s.length();i++){
		if(s[i]!=t[i]){
			ans++;
		}
	}
	cout << ans << endl;
}
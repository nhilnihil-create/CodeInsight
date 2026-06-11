/*input
cabacc
abc
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define int long long

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s,t; cin>>s>>t;
	int ans = t.size();
	for(int i=0; i<s.size(); ++i){
		int cnt=0;
		if(i+t.size() > s.size()) continue;
		for(int j=0; j<t.size(); ++j){
			if(s[i+j]!=t[j]) cnt++;
		}
		// cout<<i<<" "<<cnt<<endl;
		ans = min(ans, cnt);
	}
	cout<<ans;
	return 0;	
}
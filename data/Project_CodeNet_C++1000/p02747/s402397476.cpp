#include <bits/stdc++.h>
#define int long long 
using namespace std ;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string hi="hi",s,ans="";
	cin>>s;
	for(int i=0;i<s.size()/hi.size();i++)
		ans+=hi;

	cout<<(ans==s?"Yes":"No")<<endl;

	return 0;
}

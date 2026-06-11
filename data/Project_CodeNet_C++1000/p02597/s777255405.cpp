#include <bits/stdc++.h>
using namespace std;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, ans=0;
	string s;
	cin>>n>>s;

	int lhs=0, rhs=n-1;
	while(lhs<rhs) {
		if(s[lhs]=='R') ++lhs;
		else if(s[rhs]=='W') --rhs;
		else ++ans,++lhs,--rhs;
	}
	cout<<ans<<"\n";
	return 0;
}


#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ret return
using namespace std;
int main() {
	string res("");
	ll in;
	cin>>in;
	while(in>0) {
		in--;;
		res+=(char)('a'+in%26);
		in=in/26;
		
	}
	reverse(res.begin(),res.end());
	cout<<res<<endl;
	ret 0;
}




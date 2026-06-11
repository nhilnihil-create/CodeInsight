#include <bits/stdc++.h>
using namespace std;
int n;
string st;
int main() {
	cin>>n;
	cin>>st;
	int ans=0;
	int sum=0;
	for(int i=0;i<(int)st.size();i++) 
		if(st[i]=='W') sum++;
	if(!sum) {
		cout<<0<<endl;
		return 0;
	}
	for(int i=(int)st.size()-sum;i<(int)st.size();i++) {
		if(st[i]=='R') ans++;
	}
	cout<<ans<<endl;
	return 0;
}
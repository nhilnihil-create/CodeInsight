#include <bits/stdc++.h>
using namespace std;
signed main(void){
	string s;
	int tot=0;
	cin>>s;
	for(int i=0;i<s.size();i++) tot+=int(s[i]-'0');
	if(tot%9==0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
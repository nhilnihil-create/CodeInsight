#include <bits/stdc++.h>
using  namespace std;
int main(){
	string s;
	int n;
	cin>>n;
	cin>>s;
	for(int i=0;s[i];i++){
		s[i]+=n;
		if(s[i]>'Z') s[i]-=26;
	}
	cout<<s<<"\n";
	return 0;
}
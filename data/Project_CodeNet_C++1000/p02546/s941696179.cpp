#include<bits/stdc++.h>
using namespace std;

int main(){
	string s,ans;
   	cin>>s;
   	int a=(int)(s.length());
  	if(s[a-1]=='s') ans=s+"es";
  	else ans=s+'s';
  	cout<<ans;
  	return 0;
}
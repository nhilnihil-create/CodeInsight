#include<bits/stdc++.h>
using namespace std;
string s;
void solve(){
	cin>>s;
	if(s[2]==s[3]&&s[4]==s[5]){
		cout<<"Yes"<<endl;
	}
	else cout<<"No"<<endl;
}
int main(){
	solve();
	return 0;
}
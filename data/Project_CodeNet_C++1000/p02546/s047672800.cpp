#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	if(s.substr(s.length()-1,1)=="s"){
		cout<<s<<"es"<<endl;
	}else{
		cout<<s<<"s"<<endl;
	}
	return 0;
}

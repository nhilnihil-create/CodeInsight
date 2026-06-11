#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s.substr(i,1)=="?"){
			s.replace(i,1,"D");
		}
	}
	cout<<s<<endl;
}

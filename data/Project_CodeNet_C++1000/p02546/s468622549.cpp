#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(){
	string s;
	cin>>s;
	if(s[s.size()-1]=='s')s+="es";
	else s+="s";
	cout<<s;
	return 0;
}

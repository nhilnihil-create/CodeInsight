#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
void solve(){
	string s,t;
	cin>>s;
	cin>>t;
	int count=0;
	for(int i=0;i<s.length();i++){
		if(s[i]!=t[i])count++;
	}
	cout<<count<<"\n";
}
int main(){
	FASTIO
	solve();
	return 0;
}

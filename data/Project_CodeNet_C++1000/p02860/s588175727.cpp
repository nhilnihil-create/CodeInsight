#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define io ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	if(n&1){
		cout<<"No";
		return;
	}
	for(int i = 0;  i < n / 2; i++){
		if(s[i] != s[i + n / 2]){
			cout<<"No";
			return;
		}
	}
	cout<<"Yes";
}
int main(){
	io;
	solve();
	return 0;
}

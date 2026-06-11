#include<bits/stdc++.h>
using namespace std;

#define ll long long
//~ #define endl '\n'

void solve(){
	int n; cin>>n;
	string s; cin>>s;
	if(n&1){
		cout<<"No"<<endl;
	}else{
		n = n / 2;
		for(int i = 0; i<n; i++){
			if(s[i] != s[i + n]){
				cout<<"No"<<endl;
				return;
			}
		}
		cout<<"Yes"<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

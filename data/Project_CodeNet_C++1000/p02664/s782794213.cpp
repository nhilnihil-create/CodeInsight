#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector< int > v, ans(10004, -1);

void solve(){
	string s; cin>>s;
	for(char &i : s){
		if(i == '?'){
			i = 'D';
		}
	}
	cout<<s<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

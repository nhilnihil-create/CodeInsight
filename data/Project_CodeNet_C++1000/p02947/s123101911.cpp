#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll countNum(ll val){
	return (val - 1)*val/2;
}

int main(){
	int n;
	cin>>n;
	string str;
	map<string , ll> _mp;
	for(int i=0; i<n; i++){
		cin>>str;
		sort(str.begin(),str.end());
		_mp[str] += 1;
	}
		
	map<string, ll> :: iterator it = _mp.begin();
	
    ll ans = 0;
	
	for(;it != _mp.end(); it++) {
		if(it->second >= 2) {
			ans += countNum(it->second);
		}
	}
	cout<<ans<<endl;
}


// cat act tac dog god
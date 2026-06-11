#include<bits/stdc++.h>
using namespace std;
#define ll long long


void solve(){
	ll n;
	string s;
	cin>>n;
	cin>>s;
	ll r,g,b;
	r=g=b=0;
	for(char ch: s){
		if(ch == 'R'){
			++r;
		}else if(ch == 'G'){
			++g;
		}else if (ch == 'B'){
			++b;
		}
	}
	ll total = r*g*b;
	if(total == 0){
		cout<<total<<endl;
	}else{
		for(ll i=0;i<n;++i){
			for(ll j= i+1;j<n;++j){
				ll k = j + (j-i);
				if(k < n && (s[i] != s[j] && s[j] != s[k] && s[i] != s[k])){
				   total -=1;
				}
			}
		}
		cout<<total<<endl;
	}
}
int main()
{

  solve();

return 0;
}


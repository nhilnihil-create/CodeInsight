#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pll pair<ll,ll> 

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll x=0, y=n-1,ans=0;
	while(x<y){
		if(s[x]=='W'){
			while(x<y && s[y]!='R')
				y--;
			if(s[y]=='R'){
				ans++;
				s[x]='R';
				s[y]='W';
			}
		}
		x++;
	}
	cout<<ans<<endl;
}



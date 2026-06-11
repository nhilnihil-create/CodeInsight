#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n;
	cin>>n;
	string ans="";
	while(n){
		n--;
		ll x=n%26;
		char c=('a'+x);
		ans=c+ans;
		n/=26;
	}
	cout<<ans;
	return 0;
}

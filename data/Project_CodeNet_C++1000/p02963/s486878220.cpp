#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll s,p=1e18,q=999999999999000000;
	cin>>s;
	ll x=sqrt(s);
	if(s==p){
		cout<<0<<' '<<0<<' '<<x<<' '<<0<<' '<<0<<' '<<x<<endl;
	}else if(s>=q){
		ll num=1000000000;
		cout<<0<<' '<<0<<' '<<num<<' '<<p-s<<' '<<1<<' '<<num<<endl;
	}else cout<<0<<' '<<0<<' '<<x+1<<' '<<(x+1)*(x+1)-s<<' '<<1<<' '<<x+1<<endl;
	return 0;
}

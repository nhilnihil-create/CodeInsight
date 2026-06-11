#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,a,b,ma,mi;
	cin>>n>>a>>b;
	ma=max(a,b);
	mi=min(a,b);
	if((ma-mi)%2==0){
		cout<<(ma-mi)/2<<endl;
	}else{
		ll cnt1=mi,cnt2=n-ma+1;
		cout<<min({ma-1,n-mi,(ma-mi)/2+cnt1,(ma-mi)/2+cnt2})<<endl;
	}
	return 0;
}

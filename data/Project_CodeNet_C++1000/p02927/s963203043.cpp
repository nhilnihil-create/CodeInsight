#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
pair<ll,ll>p[114514];
int main() {
	ll m,d;
	cin>>m>>d;
	ll ans=0;
	for(int i=1;i<=m;i++){
		for(int j=10;j<=d;j++){
			ll x=j/10,y=j%10;
			if(x>=2&&y>=2&&i==x*y)ans++;
		}
	}
	cout<<ans;
	return 0;
}

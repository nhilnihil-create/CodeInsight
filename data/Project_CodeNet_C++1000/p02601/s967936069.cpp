#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll a,b,c,k;
	cin>>a>>b>>c>>k;
	for(int i=1;i<=k;i++){
		if(a>=b)b*=2;
		else if(b>=c)c*=2;
		else{
			cout<<"Yes";
			return 0;
		}
	}
	if(a<b&&b<c)cout<<"Yes";
	else cout<<"No";
	return 0;
}

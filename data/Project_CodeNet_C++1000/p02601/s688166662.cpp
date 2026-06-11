#include <bits/stdc++.h>
using namespace std;
#define long long int

signed main(){
	int a,b,c,k; cin>>a>>b>>c>>k;
	while(k--){
		if(b<=a)b*=2;
		else if(c<=b)c*=2;
	}
	if(b>a&&c>b)cout<<"Yes";
	else cout<<"No";
}

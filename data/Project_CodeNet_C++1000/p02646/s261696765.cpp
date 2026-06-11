#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll a,v,b,w,t;
	cin>>a>>v>>b>>w>>t;
	if(v<=w)cout<<"NO";
	else{
		if(t*(v-w)>=abs(a-b))cout<<"YES";
		else cout<<"NO";
	}
	return 0;
}

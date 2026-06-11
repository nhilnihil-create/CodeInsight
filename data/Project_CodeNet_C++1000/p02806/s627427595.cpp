#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n;
	ll y[110];
	string x[110],s;
	cin>>n;
	for(int i=0;i<n;i++)cin>>x[i]>>y[i];
	cin>>s;
	bool f=0;
	ll ans=0;
	for(int i=0;i<n;i++){
		if(f)ans+=y[i];
		if(x[i]==s)f=1;
	}
	cout<<ans;
	return 0;
}

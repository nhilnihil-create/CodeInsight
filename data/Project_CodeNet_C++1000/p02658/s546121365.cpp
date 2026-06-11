#include<bits/stdc++.h>
#define ll long long
#define nes ios_base :: sync_with_stdio(0); cin.tie(0);
using namespace std;
ll des=1e18;
int main(){
	nes;
	int n;
	cin>>n;
	vector<ll>v(n);
	ll mul=1;
	for(int i=0;i<n;++i){
		cin>>v[i];
		if(v[i]==0){
			cout<<0;return 0;
		}
	}
	for(int i=0;i<n;++i){
		
		if(mul>des/v[i]+des%v[i]){
			cout<<"-1";return 0;
		}
		mul*=v[i];
	}
	if(mul>des){
		cout<<"-1";return 0;
	}
	cout<<mul;
	return 0;
}
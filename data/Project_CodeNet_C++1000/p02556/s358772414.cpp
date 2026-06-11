#include<bits/stdc++.h>
#define ll long long
#define nes ios_base :: sync_with_stdio(0); cin.tie(0);
using namespace std;
ll mo=1e9+7;
ll mod(ll n){
	return (n%mo+mo)%mo;
}
ll modadd(ll a,ll b){
	return mod(mod(a)+mod(b));
}
int main(){
	nes;
	int n;
	cin>>n;
	vector<int>v1(n),v2(n);
	for(int i=0;i<n;++i){
		int x,y;
		cin>>x>>y;
		v1[i]=x+y;
		v2[i]=x-y;
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	cout<<max(v1[n-1]-v1[0],v2[n-1]-v2[0]);
	return 0;
}
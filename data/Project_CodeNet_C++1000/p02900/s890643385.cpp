#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

typedef long long ll;
const int N = 2000006;

bool np[N];
vector<ll> prims;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	np[0] = np[1] = 1;
	for(int i=4;i<N;i+=2) np[i] = 1;
	prims.push_back(2);
	for(int i=3;i<N;i+=2){
		if(!np[i]){
			prims.push_back(i);
			for(ll j = 1ll*i*i;j<N;j+=i){
				np[j] = 1;
			}
		}
	}
	
	ll a,b;
	cin>>a>>b;
	
	ll g = __gcd(a,b);
	int ans = 1;
	ll t = g;
	for(int i=0;i<(int)prims.size();i++){
		if(g % prims[i] == 0)ans++;
		while(t%prims[i] == 0) t/=prims[i];
	}
	if(t > 1)ans++;
	cout<<ans;
	
	return 0;
}

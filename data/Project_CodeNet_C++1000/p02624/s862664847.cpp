#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[10000050],n;
int main(){
	cin >> n;
	for(ll i=1; i<=n; i++){
		for(ll j=i; j<=n; j+=i){
			f[j]++;
		}
	}
	ll cnt=0;
	for(ll i=1; i<=n; i++){
		cnt+=i*f[i];
	}
	cout << cnt << endl;
}
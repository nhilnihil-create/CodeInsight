#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b;
ll i,j,k;
ll x[100005];

bool solve(){
	cin >> n >> a >> b;
	if(n + a + b == 0){
		return false;
	}
	for(i=0;i<n;i++){
		cin >> x[i];
	}
	ll num = -100;;
	ll ansind = -1;
	for(i=a-1;i<b;i++){
		ll sa = x[i] - x[i+1];
		if(sa >= num){
			num = sa;
			ansind = i;
		}
	}
	cout << ansind + 1<< endl;
	return true;
}


int main(){
	while(solve());
	return 0;
	
}

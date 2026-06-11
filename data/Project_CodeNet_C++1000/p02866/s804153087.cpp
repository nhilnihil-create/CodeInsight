#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//const int MOD = 1e9+7;
const int MOD = 998244353;

long long modpow(long long a, long long b){
	long long c = 1;
	while(b > 0){
		if(b & 1) c = c * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return c;
}

int main(){
	
	int n; cin>>n;
	vector<int> d(n);
	for(int i=0; i<n; i++){
		int d0; cin>>d0;
		if((i!=0)&&(d0==0)){
			cout << 0 << endl;
			return 0;
		}
		if((i==0)&&(d0!=0)){
			cout << 0 << endl;
			return 0;
		}
		d.at(d0)++;
	}
	ll sum{1};
	for(int i=1; i<n-1; i++){
		(sum *= modpow(d.at(i-1),d.at(i)) ) %= MOD;
		if(d.at(i)==0) break;
	}
	if(d.at(0)!=1) sum = 0;
	for(int i=0; i<n-1; i++){
		if((d.at(i)==0)&&(d.at(i+1)>0)) sum=0;
	}
	cout << sum << endl;

	
}


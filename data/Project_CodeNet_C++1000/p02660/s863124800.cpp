#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll N;
	cin >> N;
	if(N==1){cout << 0 << endl; return 0;}
	vector<int> prime;
	vector<bool> is_prime(1e6+1,true);
	is_prime[0] = is_prime[1] = false;
	for(int i=2; i<=1e6; i++){
		if(!is_prime[i])continue;
		for(int j=i; j<=1e6; j+=i) is_prime[j]=false;
		prime.push_back(i);
	}

	int ans = 0;
	ll n = N;
	for(int p : prime){
		int cnt = 0;
		while(n%p == 0){
			n /= p;
			cnt++;
		}
		for(int i=1; cnt>=i; i++) { ans++; cnt-=i;}
		if(n == 1) break;
	}
	if(n!=1)ans++;
	cout << ans << endl;
	return 0;

}

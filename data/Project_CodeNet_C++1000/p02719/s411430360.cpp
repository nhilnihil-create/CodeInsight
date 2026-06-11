#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, k;

int main(){
	cin >> n >> k;
	if(n > k){
		n %= k;
	}
	
	if(n <= k){
		if(n <= k/2)
			cout << n;
		else
			cout << k-n;
	}
	
	return 0;
}
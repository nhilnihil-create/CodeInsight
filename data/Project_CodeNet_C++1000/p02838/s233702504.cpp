#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using namespace std;

const long long mod = 1e9 + 7;

int main(){
	
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long n;
	cin >> n;
	vector<long long> a(n);
	for(long long i = 0; i < n; i++) cin >> a[i];
	long long ans = 0;

	long long two = 1;
	for(int i = 0; i < 60; i++){
		int one = 0;
		int zero = 0;
		for( long long j = 0; j < n; j++){
			 if(a[j] & (1LL << i)) one++;
		}
		//cout << one << " : " << zero << endl;
		ans += ((one * (n - one) % mod) * (two % mod)) % mod;
		two *= 2;
	}
	ans %= mod;
	cout << ans << endl;	
}

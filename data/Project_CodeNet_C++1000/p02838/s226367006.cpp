#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_set>
#include <climits>
#include <set>

using namespace std;
typedef long long ll;

const ll mod = 1000000007;

int main()
{
	ll N;
	ll A[300001];
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	static ll Sum[300001][60];
	for(int i = 0; i < 60; i++){
		Sum[N][i] = 0;
	}
	for(int i = N-1; i >= 0; i--){
		for(int j = 0; j < 60; j++){
			Sum[i][j] = Sum[i+1][j] + ((A[i] >> j) & 1);
		}
	}
	
	ll ans = 0;
	for(ll i = 0; i < N-1; i++){
		for(ll j = 0; j < 60; j++){
			if(((A[i] >> j) & 1)){
				ans += (N-1-i-Sum[i+1][j]) * ((1ll << j) % mod);
				ans %= mod;
			}else{
				ans += Sum[i+1][j] * ((1ll << j) % mod);
				ans %= mod;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
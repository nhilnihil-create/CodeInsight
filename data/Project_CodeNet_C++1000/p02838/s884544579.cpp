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
using ll = long long;
using ull = unsigned long long;

ll mod = 1e9 + 7;

int main(){	
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ull> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	vector<int> cnt(100 , 0);
	for(int i = 0; i < n; i++){
		for(int bit = 0; bit < 60; bit++){
			if(a[i] & (1LL << bit))cnt[bit]++;
		}
	}
	
	ull ans = 0;
	ull t = 1;
	ull x = 0;
	for(int bit = 0; bit < 60; bit++){
		x = (ull)cnt[bit]*(n - cnt[bit]);
		x %= mod;
		ans += (t * x)%mod;
		ans %= mod;
		t *= 2;
		t %= mod;
	}
	cout << ans << endl;
	return 0;
}
 

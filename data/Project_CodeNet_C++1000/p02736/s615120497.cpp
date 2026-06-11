#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
const int maxn = 1e6 + 3;
int n, m;
int a[maxn], cn[maxn];
int c(int i, int j){
	if(j==0||i==j) return 1;
	return  cn[i] - cn[j] - cn[i-j] <= 0;
}
int mod2() {
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(!(a[i]&1)||!c(n-1, i)) continue;
		ans ^= 1;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cn[0] = cn[1] = 0;
	cin >> n;
	for(int i = 2; i <= n; i++) cn[i] = cn[i-1] + __builtin_ctz(i);
	char t;
	int o = 0;
	for(int i = 0; i < n; i++) {
		cin >> t;
		a[i] = t-'1';
		if(1==a[i]) o = 1;
	}
	for(int i = 0; o == 0 && i < n; i++) {
		a[i]/=2;
	}
	
	cout << mod2()*(1 + (o==0));
}

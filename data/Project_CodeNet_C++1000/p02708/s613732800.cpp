#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;

long long P = 1000000007L;

long long SumModP(long long n, long long p){
	long long u = n;
	long long v;
	long long ret;

	v = (u + 1) % p;
	u = u % p;
	ret = (u * v) / 2;
	ret = ret % p;
	if(ret < 0) ret += p;
	return ret;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long N, K;
	cin >> N >> K;
	long long ans = 0;
	for(int m=K; m<=N+1; m++){
		long long v = 0;
		v = m % P;
		v = (v * N) % P;
		v -= SumModP(m-1, P);
		v = v % P;
		v -= SumModP(m-1, P);
		v = v % P;
		v += 1;
		v = v % P;
		ans += v;
		ans = ans % P;
		if(ans < 0) ans += P;
	}
	cout << ans << endl ;
	return 0;
}
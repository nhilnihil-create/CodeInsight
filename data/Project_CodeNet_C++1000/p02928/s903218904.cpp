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
long long INF = (1LL<<62);
typedef long long LL;

static LL P = 1000000007LL;

int S[2002] = {0};
int T[2002] = {0};

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N, K;
	cin >> N >> K;
	vector<LL> A;
	for(int i=0; i<N; i++){
		LL a; cin >> a;
		A.push_back(a);
	}

	for(int i=0; i<N; i++){
		LL a = A[i];
		for(int j=0; j<N; j++){
			LL b = A[j];
			if(b < a){
				S[i]++;
				if(j > i){
					T[i]++;
				}
			}
		}
	}
	LL ans = 0;
	if(K == 1){
		for(int i=0; i<N; i++){
			ans += T[i];
			ans %= P;
		}
		ans %= P;
		printf("%lld\n", ans);
		return 0;
	}

	for(int i=0; i<N; i++){
		LL s = S[i];
		LL t = T[i];
		K %= P;
		LL u = (t * K) % P;
		ans += u;
		ans %= P;
		LL v = (K*(K-1))/2;
		v %= P;
		v *= s;
		v %= P;
		ans += v;
		ans %= P;
	}
	ans %= P;
	printf("%lld\n", ans);
	return 0;
}

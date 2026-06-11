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
typedef long long LL;
using Graph = vector<vector<int>>;

// 素数判定
// ret: 1 -> prime, 0-> not prime
int isPrime(LL p){
	if(p<=1) return 0;
	if(p==2 || p==3 || p==5 || p==7) return 1;
	if(p==4 || p==6 || p==8 || p==9) return 0;

	LL i;
	int ret = 1;
	for(i=2; i*i<=p; i++){
		if(p%i==0 && i!=p){
			ret = 0;
			break;
		}
	}
	return ret;
}

// 最大公約数を求める(ユークリッド互除法)
LL GCD(LL x, LL y){
        LL r=0;

	if( x<y ) swap(x, y);
        r = x % y;
        while(r!=0){
                x = y;
                y = r;
                r = x % y;
        }
        return y;
}

// N を素因数分解して mp に格納する。long longは素数、intは指数。
void factorize(long long N, map<long long, int> &mp){
	if(N == 1){
		return;
	}
	if(isPrime(N)){
		mp[N] += 1;
		return;
	}

	long long i = 2, n = N;
	for(i = 2; n != 1 && i < (N/2) + 1; i++){
		if((n % i)==0){
			if(isPrime(i)){
				int e = 0;
				long long u = n;
				while((u % i)==0){
					e++;
					u = u / i;
					n = u;
				}
				mp[i] = e;
				if(isPrime(n)){
					mp[n] = 1;
					break;
				}
			}
		}
	}
	return;
}

LL A, B;
int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> A >> B;
	long long D = GCD(A, B);
	map<LL, int> mp;
	factorize(D, mp);
	int P = mp.size();
	printf("%d\n", P + 1);
	return 0;
}
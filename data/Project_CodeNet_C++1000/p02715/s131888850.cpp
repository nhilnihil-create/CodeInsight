#include<bits/stdc++.h>
using namespace std;

#define DIV 1000000007

long long N, K;
map<long long, long long>numcount;
map<long long, long long>ans;

long long kaidan[10000000];

long long modpow(long long ori, long long po){
	long long res = 1;
	while(po > 0){
		if(po&1){
			res *= ori;
			res %= DIV;
		}
		ori *= ori;
		ori %= DIV;
		po >>= 1;
	}
	return res;
}

int main(){
	cin >> N >> K;

	for(long long num = 1; num<=K; num++) {
		for(long long i = 1; i * i <= num; i++) {
			if(num%i == 0) {
				numcount[i]++;
				if(i != num/i) {
					numcount[num/i]++;
				}
			}
		}
	}

	long long pri = 0;
	for(long long i = K; i>=1; i--) {
		//numこの数字を使ってNの長さを作る
		long long num = numcount[i];

		//N + num - 1 C num - 1
		long long tmp = modpow(num, N);

		for(long long j = 2; i * j <= K; j++) {
			tmp -= ans[i * j];
			tmp = (tmp + DIV)%DIV;
		}
		ans[i] = tmp;

		pri += i * tmp;
		pri %= DIV;
	}
	cout << pri << endl;

}

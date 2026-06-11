#include<bits/stdc++.h>
using namespace std;

long long N, P;
string S;

long long memo[200005];
map<long long, long long>pcount;
long long kaidan[10000000];

long long modpow(long long ori, long long po){
	long long res = 1;
	while(po > 0){
		if(po&1){
			res *= ori;
			res %= P;
		}
		ori *= ori;
		ori %= P;
		po >>= 1;
	}
	return res;
}


int main(){
	cin >> N >> P >> S;

	if(P == 2 || P == 5){
		long long num = 0;
		for(long long i = 0; i < N; i++) {
			if((S[i] - '0') % P == 0) {
				num +=  i + 1;
			}
		}
		cout << num << endl;

		return 0;
	}

	for(long long i = 0; i < N; i++) {
		memo[i+1] = memo[i] + (S[N-1-i] - '0') * modpow(10, i);
		memo[i+1] %= P;
		pcount[memo[i+1]]++;
	}
	//for(long long i = 0; i <= N; i++) {
	//	cout << "memo[" << i << "] = " << memo[i] << endl;
	//}


	long long ans = 0;
	for(auto item: pcount) {
		//cout << item.first << ", " << item.second << endl;
		if(item.first == 0) {
			ans += (item.second * (item.second - 1))/2 + item.second;
		} else {
			ans += (item.second * (item.second - 1))/2;
		}
	}
	cout << ans << endl;
}


#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map> 
#include <unordered_set>
#include <functional>
#include <bitset>

using namespace std;

typedef pair<long long int, long long int> P;
typedef pair<long long int, P> P2;
typedef tuple<int, int, int> T;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

long long int pow_n(long long int num, long long int pow_num){
	long long int mod_num = MOD;
	long long int pow_cur = num;
	long long int ret = 1;
	while(pow_num > 0){
		if(pow_num % 2 == 1){
			ret *= pow_cur;
			ret %= mod_num;
		}
		pow_cur *= pow_cur;
		pow_cur %= mod_num;
		pow_num /= 2;
	}
	return ret;
}

int main(){
	long long int N, P;
	cin >> N >> P;
	MOD = P;
	string S;
	cin >> S;
	long long int ans = 0;
	if(P == 2 || P == 5){
		for(int i = 0; i < N; i++){
			if((S[i] - '0') % P == 0){
				ans += i + 1;
			}
		}
		cout << ans << endl;
		return 0;
	}
	map<long long int, long long int> m;
	long long int cur = 0;
	m[0] = 1;
	for(int i = N - 1; i >= 0; i--){
		cur += (S[i] - '0') * pow_n(10, N - 1 - i);
		cur %= P;
		ans += m[cur];
		m[cur] += 1;
	}
	cout << ans << endl;
	return 0;
}

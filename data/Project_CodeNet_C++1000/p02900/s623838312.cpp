#include<bits/stdc++.h>
using namespace std;
#define LL long long

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}


int main(){
	// sengen
	LL a,b;
	LL j[1000];
	// nyuryoku
	cin >> a >> b;
	LL g = gcd(a,b);
	const auto &gp = prime_factorize(g);
	LL ans = 1;
	for(auto x:gp){
		ans++;
	}
	// keisan
	cout << ans << endl;
	// syutsuryoku
}
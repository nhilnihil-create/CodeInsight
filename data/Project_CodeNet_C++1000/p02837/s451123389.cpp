#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

//正直
#define YES 1
//不親切
#define NO 0

//未定
#define MITEI 2

long long N;
//xの人が正直と言っている人
vector<long long> shozi[20];
//xの人が不親切と言っている人
vector<long long> hushi[20];

long long memo[20];

int main(){
	cin >> N;
	rep(i, N) {
		long long a;
		cin >> a;
		rep(j, a) {
			long long x, y;
			cin >> x >> y;
			x--;
			if(y == YES) {
				shozi[i].push_back(x);
			} else {
				hushi[i].push_back(x);
			}
		}
	}


	long long ans = 0;
	rep(pat, (1<<N)) {
		rep(i, N) memo[i] = MITEI;

		bool ok = true;
		rep(from, N) {
			if((pat>>from)&1) {
				if(memo[from] == NO) {
					ok = false;
				}
				memo[from] = YES;
			} else {
				if(memo[from] == YES) {
					ok = false;
				}
				memo[from] = NO;
			}

			//fromが正直もの？
			if((pat>>from)&1) {
				for(auto p: shozi[from]) {
					if(memo[p] == NO) {
						ok = false;
					}
					memo[p] = YES;
				}

				for(auto p: hushi[from]) {
					if(memo[p] == YES) {
						ok = false;
					}
					memo[p] = NO;
				}
			}
		}
		if(ok) {
			ans = max(ans, (long long)__builtin_popcountll(pat));
		}
	}
	cout << ans << endl;
}

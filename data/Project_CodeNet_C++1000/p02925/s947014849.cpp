#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N;
ll A[1001][1001];
ll dayidxs[1001];

int main(){
	cin >> N;
	rep(i, N) rep(j, N - 1) {
		cin >> A[i][j];
		A[i][j]--;
	}


	for(ll day = 0; day >= 0; day++) {
		set<ll> done;

		bool has = false;
		bool change = false;
		rep(zibun, N) {
			ll dayidx = dayidxs[zibun];
			if(dayidx >= N-1) continue;
			has = true;
			if(done.count(zibun) > 0) continue;

			ll teki = A[zibun][dayidx];
			if(dayidxs[teki] < N - 1 && A[teki][dayidxs[teki]] == zibun && done.count(teki) == 0) {
				change = true;
				done.insert(zibun);
				done.insert(teki);
				dayidxs[zibun]++;
				dayidxs[teki]++;
			}
		}

		if(!has) {
			cout <<  day << endl;
			return 0;
		}
		if(!change) {
			cout <<  -1 << endl;
			return 0;
		}
	}
}
// D - Moving Piece
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	int N, K; cin>>N>>K;
	vector<int> P(N), C(N);
	rep(i, N) cin>>P[i], P[i]--;
	rep(i, N) cin>>C[i];

	ll score = -1e18;
	rep(st, N){
		ll lap_sc = 0, sum_sc = 0;
		int nx = st, lap_cn = 0;
		rep(i, N){
			lap_sc += C[nx];
			if(st == (nx = P[nx])){
				lap_cn = i + 1;
				break;
			}
		}
		lap_sc = max(0LL, lap_sc);

		rep(k_cn, K){
			sum_sc += C[nx];
			score = max(score, sum_sc + lap_sc * ((K - (k_cn + 1)) / lap_cn));
			if(st == (nx = P[nx])) break;
		}
	}
	cout<< score <<endl;
}

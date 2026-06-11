// D - Moving Piece
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define chmax(x,y) x = max(x,y)

int main(){
	int N, K; cin>>N>>K;
	vector<int> P(N), C(N);
	rep(i, N) cin>>P[i], P[i]--;
	rep(i, N) cin>>C[i];

	int64_t score = -1e18;
	rep(st, N){
		int64_t lap_sc = 0, sum_sc = 0;
		int nx = st, lap_cn = 1;
		for(; lap_cn<=N; ++lap_cn){
			lap_sc += C[nx];
			if(st == (nx = P[nx])) break;
		}
		chmax(lap_sc, 0L);

		for(int k_cn=1; k_cn<=K; ++k_cn){
			sum_sc += C[nx];
			chmax(score, sum_sc + lap_sc * ((K - k_cn) / lap_cn));
			if(st == (nx = P[nx])) break;
		}
	}
	cout<< score <<endl;
}

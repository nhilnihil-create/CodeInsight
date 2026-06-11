// D - Moving Piece
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	int N, K; cin>>N>>K;
	vi P(N); rep(i, N) cin>>P[i], P[i]--;
	vi C(N); rep(i, N) cin>>C[i];

	ll INF = 1e18;
	ll score = -INF;
	rep(st, N){
		ll lap_sc = 0;
		int lap_cn = 0;
		int nx = st;
		while(true){
			lap_cn++;
			lap_sc += C[nx];
			if(st == (nx = P[nx])) break;
		}
		lap_sc = max(0LL, lap_sc);

		ll sum_sc = 0;
		for(int k_cn=1; k_cn<=K; k_cn++){
			sum_sc += C[nx];
			score = max(score, sum_sc + lap_sc * ((K - k_cn) / lap_cn));
			if(st == (nx = P[nx])) break;
		}
	}
	cout<< score <<endl;
}

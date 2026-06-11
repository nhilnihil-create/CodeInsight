// C - Lamps
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	int N, K; cin>>N>>K;
	vi A(N); rep(i, N) cin>>A[i];
	vi B;
	rep(i, K){
		B = vi(N, 0);
		rep(j, N){
			int l = max(0, j-A[j]);
			int r = j + A[j] + 1;
			B[l]++;
			if(r <= N-1) B[r]--;
		}
		bool is_same = true;
		rep(j, N-1){
			B[j+1] += B[j];
			if(B[j+1] != N) is_same = false;
		}
		if(is_same) break;
		A = B;
	}
	rep(i, N) cout<< B[i] << (i+1==N? "\n":" ");
}

// C - Lamps
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	int N, K; cin>>N>>K;
	vi A(N); rep(i, N) cin>>A[i];
	rep(i, K){
		vi B(N+1);
		rep(j, N){
			int l = max(0, j - A[j]);
			int r = min(N, j + A[j] + 1);
			B[l]++, B[r]--;
		}
		rep(j, N-1) B[j+1] += B[j];
		B.pop_back();
		if(A == B) break;
		A = B;
	}
	rep(i, N) cout<< A[i] << (i+1==N? "\n":" ");
}

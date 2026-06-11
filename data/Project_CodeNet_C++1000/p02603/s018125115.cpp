// D - Road to Millionaire
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	int N; cin>>N;
	vector<int> A(N);
	rep(i, N) cin>>A[i];
	int64_t yen = 1000;
	rep(i, N-1) yen += max(0L, yen/A[i] * (A[i+1] - A[i]));
	cout<< yen <<endl;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;

const int dir_h[] = {-1, 0, 1, 0};
const int dir_w[] = { 0,-1, 0, 1};

int main(){
	int64_t N;
	cin >> N;
	vector<int64_t> A(N);
	vector<int64_t> sum(N);
	rep(i, N) cin >> A[i];
	rep(i, N){
		if(i != 0){
			sum[i] = sum[i-1] + A[i];
		}
		else{
			sum[i] = A[i];
		}
	}
	int64_t ans = -1;
	for(int i = 0; i < N-1; ++i){
		int64_t left = sum[i];
		int64_t right = sum[N-1] - left;
		if(ans == -1){
			ans = abs(right - left);
		}
		else{
			ans = min(ans, abs(right - left));
		}
	}
	cout << ans << endl;
	return 0;
}

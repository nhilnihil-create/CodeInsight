#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back

int main(){
	int N, K;
	cin >> N >> K;
	if(K == 1) K = N;
	cout << max(N - K, 0) << endl;
}

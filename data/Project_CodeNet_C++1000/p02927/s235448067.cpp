#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back

int main(){
	int M,D;
	cin >> M >> D;

	int ans = 0;
	for(int m = 1; m <= M; m++){
		for(int d = 22; d <= D; d++){
			if(d % 10 < 2) continue;
			if(m == (d%10)*(d/10)) ans++;
		}
	}

	cout << ans << endl;
}

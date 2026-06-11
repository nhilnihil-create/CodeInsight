#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)
typedef long long ll;

int main(){
	int N;
	cin >> N;

	vector<ll> A(N);
	ll sum = 0;
	rep(i, N){
		cin >> A.at(i);
		sum += A.at(i);
	}
	ll ans = sum;
	ll tmp = 0;
	rep(i, N){
		tmp += A.at(i);
		ans = min(ans, abs(sum - tmp * 2));
	}
	cout << ans << endl;
}


#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)

using namespace std;

int main(){
	long long N, K;
	cin >> N >> K;
	vector<long long> H;
	rep(i, N) {
		long long tmp;
		cin >> tmp;
		H.push_back(tmp);
	}
	sort(H.begin(), H.end(), greater<long long>());

	if(H.size() <= K) {
		cout << 0 << endl;
	} else {
		long long ans = 0;
		for(long long i = K; i < H.size(); i++) {
			ans += H[i];
		}
		cout << ans << endl;
	}
}
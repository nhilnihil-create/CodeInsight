#include<bits/stdc++.h>
using namespace std;

int main(){
	long long N;
	__int128 ans = 1;
	cin >> N;

	bool ng = false;
	bool zero = false;
	for(long long i = 0; i < N; i++) {
		long long tmp;
		cin >> tmp;
		if(tmp == 0) {
			zero = true;
		}

		__int128 a = tmp;

		ans *= a;
		if(ans > 1000000000000000000) {
			ng = true;
		}
	}

	if(zero) {
		cout << 0 << endl;
	} else if(ng) {
		cout << -1 << endl;
	} else {
		long long hoge = ans;
		cout << hoge << endl;
	}

}
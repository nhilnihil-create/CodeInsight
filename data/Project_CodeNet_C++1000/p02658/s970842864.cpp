#include<bits/stdc++.h>
using namespace std;
 
int main(){
	long long N;
	unsigned long long ans = 1;
	cin >> N;
 
	bool zero = false;
	bool ng = false;
	for(long long i = 0; i < N; i++) {
		unsigned long long tmp;
		cin >> tmp;
		if(tmp == 0) {
			zero = true;
		}
		if(!zero && 1000000000000000000/ans < tmp) {
			ng = true;
		}
		if(!zero && !ng) {
			ans *= tmp;
		}
	}
 
	if(zero) {
		cout << 0 << endl;
	} else if(ng) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}

}
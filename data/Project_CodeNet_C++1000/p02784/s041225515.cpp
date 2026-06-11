#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)

using namespace std;

int main(){
	long long H, N;
	cin >> H >> N;
	long long sum = 0;
	rep(i, N) {
		long long tmp;
		cin >> tmp;
		sum += tmp;
	}
	if(sum >= H) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

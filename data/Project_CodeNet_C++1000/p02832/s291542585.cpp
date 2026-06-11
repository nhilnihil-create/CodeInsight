#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long N;
long long A[200005];

int main(){
	cin >> N;
	rep(i, N) {
		cin >> A[i];
	}

	long long cur = 1;
	rep(i, N) {
		if(cur == A[i]) {
			cur++;
		}
	}
	if(cur == 1)  {
		cout << -1 << endl;
		return 0;
	}
	cout << N - cur + 1<< endl;

}

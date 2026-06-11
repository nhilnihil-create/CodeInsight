#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long N;

int main(){
	cin >> N;
	if(N % 2 == 1) {
		cout << 0 << endl;
		return 0;
	}

	long long fivecount = 0;
	for(long long i = 5; i <= N/2; i*=5) {
		fivecount += N/2/i;
	}

	long long twocount = N/2;
	for(long long i = 2; i <= N/2; i*=2) {
		twocount += N/2/i;
	}

	cout << min(twocount, fivecount) << endl;

}
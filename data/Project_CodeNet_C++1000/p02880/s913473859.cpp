#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long N;

int main(){
	cin >> N;
	for(long long i = 1; i < 10; i++) {
	for(long long j = 1; j < 10; j++) {
		if(i * j == N) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	}

	cout << "No" << endl; return 0;
}
#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long N, K;
long long h[505];

int main(){
	cin >> N >> K;
	long long h;
	long long num = 0;
	rep(i, N) {
		cin >> h;
		if(h >= K) num++;
	}
	cout << num << endl;
}
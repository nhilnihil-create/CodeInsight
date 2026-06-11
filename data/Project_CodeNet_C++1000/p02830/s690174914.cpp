#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long N;
string S, T;
int main(){
	cin >> N;
	cin >> S >> T;
	rep(i, N) {
		cout << S[i] << T[i];
	}
	cout << endl;
}
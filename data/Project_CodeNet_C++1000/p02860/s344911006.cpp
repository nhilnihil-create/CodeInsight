#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;
long long N;
string S;

int main(){
	cin >> N >> S;
	if(N % 2 == 0 && S.substr(0, N/2) == S.substr(N/2, N)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

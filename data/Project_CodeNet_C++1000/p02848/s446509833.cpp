#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long N;
string S;

int main(){
	cin >> N >> S;
	rep(i, S.size()) {
		cout << char('A' + (S[i] - 'A' + N)%26);
	}
	cout << endl;

}
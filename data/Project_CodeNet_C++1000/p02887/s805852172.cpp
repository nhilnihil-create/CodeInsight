#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long N;
string S;

int main(){
	cin >> N >> S;

	char cur = '_';
	long long num = 0;

	rep(i, N) {
		char ch = S[i];
		if(ch != cur) {
			num++;
			cur = ch;
		}
	}
	cout << num << endl;

}
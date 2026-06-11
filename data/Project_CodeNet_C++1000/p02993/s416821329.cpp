#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	string S;
	cin >> S;
	if(S[0] == S[1] || S[1] == S[2] || S[2] == S[3]) {
		cout << "Bad" << endl;
	} else {
		cout << "Good" << endl;
	}
}

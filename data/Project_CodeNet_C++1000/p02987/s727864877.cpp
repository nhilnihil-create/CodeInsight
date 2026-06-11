#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	string S;
	cin >> S;

	map<char, ll> memo;
	rep(i, S.size()) memo[S[i]]++;
	if(memo.size() == 2 && (*memo.begin()).second == 2) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	string S, T;
	cin >> S >> T;
	ll num = 0;
	rep(i, 3) {
		if(S[i] == T[i])
			num++;
	}
	cout << num << endl;

}


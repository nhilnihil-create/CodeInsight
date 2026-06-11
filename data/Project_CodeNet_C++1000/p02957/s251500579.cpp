#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	ll A, B;
	cin >> A >> B;
	if(A == B) {
		cout << 0 << endl;
	} else {
		if((A+B)%2 == 1) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			cout << (A+B)/2 << endl;
		}
	}
}


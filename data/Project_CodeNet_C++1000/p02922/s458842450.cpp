#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	ll A, B;
	cin >> A >> B;
	ll num = 1;

	rep(i, 100) {
		if(num >= B) {
			cout << i << endl;
			return 0;
		}
		num += (A - 1);
	}

}
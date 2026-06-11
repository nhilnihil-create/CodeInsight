#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

int main(){
	long long A, B;
	cin >> A >> B;
	cout << max(0LL, A - 2 * B) << endl;

}
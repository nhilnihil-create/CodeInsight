#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	ll N, D;
	cin >> N >> D;
	D = D * 2 + 1;
	cout << (N + D - 1) / D << endl;

}


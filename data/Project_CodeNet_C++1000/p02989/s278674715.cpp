#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	ll N;
	cin >> N;

	vector<ll> D(N);
	rep(i, N) cin >> D[i];

	sort(D.begin(), D.end());

	cout << D[N/2] - D[N/2 - 1] << endl;
}

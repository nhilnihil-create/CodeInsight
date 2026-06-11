#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> A;
 
signed main(){
	int N;
	cin >> N;
	A = vector<ll>(N);
	for(int i = 0; i < N; i++){
		cin >> A.at(i);
	}
	ll money = 1000;
	for(int i = 0; i < N-1; i++){
		if(A.at(i) < A.at(i+1)){
			money = money%A.at(i)+money/A.at(i)*A.at(i+1);
		}
	}
	cout << money << endl;
 
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
	ll x; cin >> x;
	ll cur = 100;
	int moves = 0;
	while(cur < x){
		cur += cur/100ll;
		moves++;
	}
	cout << moves << endl;

	return 0;
}
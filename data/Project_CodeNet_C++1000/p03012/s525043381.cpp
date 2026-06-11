#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int n;
	cin >> n;
	vector<int> w(n);
	int sum = 0;
	rep(i, n){
		cin >> w.at(i);
		sum += w.at(i);
	}

	int diff = sum;
	int leave;
	int acc = 0;
	rep(i, n){
		acc += w.at(i);
		leave = sum - acc;
		diff = min(diff,abs(acc - leave));
	}

	cout << diff << endl;
}
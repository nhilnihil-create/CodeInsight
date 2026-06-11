#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	int n;
	cin >> n;

	int sum = 0;
	vector<int> w(n);
	rep(i, n){
		cin >> w.at(i);
		sum += w.at(i);
	}

	int ma = 100;
	int now = 0;
	rep(i, n){
		now += w.at(i);
		int leave = sum-now;
		ma = min(ma, abs(leave-now));
	}
	
	cout << ma << endl;

	return 0;
}

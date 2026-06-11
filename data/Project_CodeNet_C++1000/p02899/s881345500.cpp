#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)



int main() {
	int N,m;
	cin >> N;
	vector<int> vec(N);
	rep(i, N) {
		cin >> m;
		vec.at(m - 1) = i + 1;
	}
	rep(i, N) {
		cout << vec.at(i) << " ";
	}
}
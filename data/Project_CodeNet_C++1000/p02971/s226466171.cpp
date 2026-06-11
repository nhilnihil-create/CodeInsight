#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 100000000;
typedef pair<int, int> P;
const int MAX_N = 1000000;



int main() {
	int64_t N;
	cin >> N;
	vector<int64_t> vec(N);
	vector<int64_t> tmp(N);
	
	rep(i, N) {
		cin>>vec.at(i);
		tmp.at(i) = vec.at(i);
	}
	
	sort(vec.begin(), vec.end());

	rep(i, N) {
		if (tmp.at(i) == vec.at(N - 1)) {
			cout << vec.at(N - 2) << endl;
		}
		else {
			cout << vec.at(N - 1) << endl;
		}
	}
}
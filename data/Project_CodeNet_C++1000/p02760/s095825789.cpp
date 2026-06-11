#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
typedef pair<int, int> P;
typedef int64_t ll;
const int MAX_N = 10000;
const int INF = 1000000000;


int main() {
	Graph A(3, vector<int>(3));
	rep(i, 3)rep(j, 3) {
		cin >> A.at(i).at(j);
	}
	int N;
	cin >> N;
	vector<int> B(N);
	rep(k, N) {
		cin >> B.at(k);
	}
	rep(k, N) {
		rep(i, 3)rep(j, 3) {
			if (B.at(k) == A.at(i).at(j))A.at(i).at(j) = 0;
		}
	}
	
	rep(i, 3) {
		int cntR = 0;
		int cntC = 0;
		rep(j, 3) {
			if (A.at(i).at(j) == 0)cntR++;
			if (A.at(j).at(i) == 0)cntC++;
		}
		if (cntR == 3|| cntC==3) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	if (A[0][0]==0&& A[1][1] == 0 && A[2][2] == 0)
	{
		cout << "Yes" << endl;
		return 0;
	}
	if (A[0][2] == 0 && A[1][1] == 0 && A[2][0] == 0) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
	return 0;
}
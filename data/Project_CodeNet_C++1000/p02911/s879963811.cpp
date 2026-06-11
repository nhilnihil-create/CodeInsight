#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 100000000;
typedef pair<int, int> P;
const int MAX_N = 1000000;

int N, K, Q;


int main() {
	cin >> N >> K >> Q;
	vector<int> vec(N, K);
	rep(i, N) {
		vec.at(i) -= Q;
	}
	int tmp;
	rep(i, Q) {
		cin >> tmp;
		vec.at(tmp-1) += 1;
	}
	rep(i, N) {
		if (vec.at(i)<=0)
		{
			cout << "No"<< endl;
			
		}
		else {
			cout << "Yes" << endl;
		}
	}
}
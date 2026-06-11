#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
typedef pair<int, int> P;
const int MAX_N = 1000000000;
const int MAX_L = 100000000;
const int MAX_SQRT_B = 10000;
const int INF = 1000000000;
typedef int64_t ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int N;
int A[100005];
int B[100005];

int main() {
	cin >> N;
	rep(i, N + 1) {
		cin >> A[i];
	}
	rep(i, N) {
		cin >> B[i];
	}

	ll tmp = 0;
	for (int i = 0; i < N; i++)
	{
		if (A[i] - B[i] > 0)
		{
			tmp += B[i];
		}
		else {
			ll tt;
			tmp += A[i];
			tt = B[i] - A[i];
			if (A[i + 1] - tt > 0) {
				tmp += tt;
				A[i + 1] = A[i + 1] - tt;
			}
			else {
				tmp += A[i + 1];
				A[i + 1] = 0;
			}
		}
	}
	cout << tmp << endl;
}

#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;


int A[510];
int sum[10000];
vector<int> V;
vector<int> a[10000];
int main()
{
	int N, K;
	cin >> N >> K;
	int S = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		S += A[i];
	}
	for (int i = 1; i * i <= S; i++) {
		if (S % i == 0) {
			if (i * i != S) V.push_back(S / i);
			V.push_back(i);
		}
	}
	sort(V.rbegin(), V.rend());
	for (int i = 0; i < V.size();i++) {
		for (int j = 0; j < N; j++) {
			a[i].push_back(A[j] % V[i]);
			sum[i] += (A[j] % V[i]);
		}
		sort(a[i].rbegin(), a[i].rend());
	}
	for (int i = 0; i < V.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			sum[i] -= a[i][j];
			cnt += V[i] - a[i][j];
			if (cnt == sum[i] && cnt <= K) {
				cout << V[i] << endl;
				return 0;
			}
		}
	}
	cout << 1 << endl;
}
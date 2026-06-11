#include<iostream>
#include <climits>
#include<vector>
#include<numeric>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int insertionSort(vector<ll> &A, int n, int g) {
	int cnt = 0;
	for (int i = g;i < n;i++) {
		int j = i;
		while (j - g >= 0 && A[j - g] > A[j]) {
			ll tmp = A[j - g];
			A[j - g] = A[j];
			A[j] = tmp;
			j -= g;
			cnt++;
		}
	}
	return cnt;
}

void shellSort(vector<ll> &A, int n) {
	int cnt = 0;
	vector<int> G;
	G.push_back(1);
	for (int i = 1;G[i - 1] <= n / 4;i++) G.push_back(2 * G[i - 1]);
	reverse(G.begin(), G.end());
	int m = G.size();
	for (int i = 0;i < m;i++) cnt += insertionSort(A, n, G[i]);
	cout << m << "\n";
	for (int i = 0;i < m;i++) {
		if (i != m - 1) cout << G[i] << " ";
		else cout << G[i] << "\n";
	}
	cout << cnt << "\n";
	for (int i = 0;i < n;i++) cout << A[i] << "\n";
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<ll> A(n);
	REP(i, n) cin >> A[i];
	shellSort(A, n);

	return 0;
}

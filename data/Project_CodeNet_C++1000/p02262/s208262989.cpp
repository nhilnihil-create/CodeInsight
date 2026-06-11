#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <sstream>

#define REP(i,n) for(int i=0;i<n;++i)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define FOR(i,m,n) for(int i=m;i<n;++i)
#define RFOR(i,m,n) for(int i=m-1;i>=n;--i)
#define ALL(v) v.begin(),v.end()
#define pb(a) push_back(a)
#define INF 1000000001
#define MOD 1000000007

using namespace std;

int cnt = 0;
void insertionSort(vector<int> &A, int n, int g) {
	FOR(i, g, n) {
		int v = A[i];
		int j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j + g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j + g] = v;
	}
}


int main() {
	int n;

	vector<int> a;
	cin >> n;
	int b = n;
	REP(i, n) {
		int b;
		cin >> b;
		a.pb(b);
	}
	int m = 0;
	while (b > 0) {
		b /= 2;
		m++;
	}
	m = max(1, m - 1);
	vector<int> g;
	RREP(i, m) {
		g.pb((int)pow(2, i));
	}
	REP(i, m) {
		insertionSort(a, n, g[i]);
	}
	cout << m << endl;
	REP(i, m) {
		cout << g[i];
		if (i != m - 1) cout << " ";
	}
	cout << endl;
	cout << cnt << endl;
	REP(i, n) {
		cout << a[i] << endl;
	}
	cout << endl;

	return 0;
}
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

typedef vector<int> vi;

template<typename T>
static inline void p(T x) { cout << x << endl; }

int main()
{
    cin.sync_with_stdio(false);

	int n, cnt = 0;
	cin >> n;

	vi A(n), G;
	for (int &x: A)
		cin >> x;

	for (int i = 1, x = 1; x <= n; x = (pow(3, ++i) - 1) / 2)
		G.push_back(x);
	reverse(G.begin(), G.end());

	for (int g: G)
		for (int i = g; i < n; i++) {
			int v = A[i], j = i - g;
			for(; j >= 0 && A[j] > v; j -= g)
				A[j+g] = A[j], cnt++;
			A[j+g] = v;
		}

	p(G.size());
	for (int &x: G)
		cout << (&x == &G[0] ? "" : " ") << x;
	p("");
	p(cnt);
	for (int x: A)
		p(x);
}

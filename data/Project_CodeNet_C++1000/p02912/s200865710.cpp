#include <bits/stdc++.h>
using namespace std;

#pragma warning( disable : 4996 )

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ss(s) scanf("%s", &s)
#define pi(n) printf("%d\n", n)
#define pll(n) printf("%lld\n", n)
#define ps(s) printf("%s\n", s)
#define FOR(i, a, b) for (int i=a;i<=b;i++)

typedef long long ll;

void max_heapify(vector<int> &a, int i) {
	int largest = i;
	int l = 2 * i;
	int r = 2 * i + 1;
	if (l <= (int) a.size()-1 && a[l] > a[i]) {
		largest = l;
	}
	if (r <= (int)a.size()-1 && a[r] > a[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(a[i], a[largest]);
		max_heapify(a, largest);
	}
}

void build_maxheap(vector<int> &a) {
	for (int i = (a.size()-1) / 2; i >= 1; i--) {
		max_heapify(a, i);
	}
}

void print_vec(vector<int> a) {
	for (int i = 0; i < a.size() - 1; i++) {
		cout << a[i] << ' ';
	}
	cout << a.back() << endl;
}

void solve() {
	//input
	int n, m;
	si(n);
	si(m);
	vector<int> a(n+1);
	FOR(i, 1, n) {
		int temp;
		si(temp);
		a[i] = temp;
	}
	//heapify
	build_maxheap(a);

	//implementation
	while (m--) {
		a[1] /= 2;
		max_heapify(a, 1);
	}

	//output
	ll sum = 0;
	FOR(i, 1, n) sum += (ll)a[i];
	cout << sum << endl;
}

int main() {
	solve();
}
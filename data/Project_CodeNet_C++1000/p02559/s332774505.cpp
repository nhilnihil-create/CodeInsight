
using namespace std;

//#define fileio

#ifndef fileio
#include <iostream>
#endif
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>

typedef long long ll;

#ifdef fileio
ifstream cin;
ofstream cout;
#endif


//point update, range query, 0-indexed
struct bit {
	vector<long long> b;
	void init(int n) { b.resize(n + 1); }
	bit() {}
	bit(int n) { init(n); }
	inline void update(int i, long long v) {
		for (++i; i < (int)b.size(); i += i & -i)
			b[i] += v;
	}
	//sum of the first i values
	long long prefix(int i) const {
		long long a = 0;
		for (; i; i ^= i & -i)
			a += b[i];
		return a;
	}
	inline long long query(int l, int r) const {
		return prefix(r + 1) - prefix(l);
	}
};



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef fileio
    cin.open("Text.txt");
    cout.open("Output.txt");
#endif
	int n, q;
	cin >> n >> q;

	bit b(n+1);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		b.update(i, x);
	}
	while (q-- > 0) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 0) {
			b.update(y, z);
		}
		else {
			cout << b.query(y, z - 1) << endl;
		}
	}


}

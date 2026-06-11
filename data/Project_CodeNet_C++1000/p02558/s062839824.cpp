
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


struct uf {
	vector<int> rt, sz;

	uf(int n) {
		rt.resize(n);
		sz.resize(n);
		for (int i = 0; i < n; i++) {
			rt[i] = i;
			sz[i] = 1;
		}
}

	int id(int x) {
		if (rt[x] == x) return x;
		return rt[x] = id(rt[x]);
	}

	bool join(int x, int y) {
		x = id(x);
		y = id(y);
		if (x == y) return false;
		rt[x] = rt[y];
		sz[y] += sz[x];
		sz[x] = 0;
		return true;
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
	uf uf(n);
    while (q-- > 0) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 0) {
			uf.join(y, z);
        }
        else {
			cout << (uf.id(y) == uf.id(z)) << endl;
        }
    }

}

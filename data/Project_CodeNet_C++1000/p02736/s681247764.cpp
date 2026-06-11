#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<unordered_map>
#include<random>
#include<array>
#include<cassert>
using namespace std;
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())



int fact2(int n) {
	int p2 = 2;
	int r = 0;
	while (p2 <= n) {
		r += n / p2;
		p2 *= 2;
	}

	return r;
}

int C2(int n, int r) {
	if (n < 0 || r < 0 || r > n)return 0;
	if (r > n / 2)r = n - r;
	int a = n, b = n - r, c = r;

	return fact2(a) - fact2(b) - fact2(c);
}

bool is1(vector<int> v) {
	int n = v.size();
	uint32_t x = 0;
	
	for (int i = 0; i < n; i++) {
		if (C2(n - 1, i) == 0) x += v[i];
	}
	x &= 1;

	return x == 1;
}

bool is2(vector<int> v) {
	int n = v.size();
	if( count(all(v), 1)) return false;

	for (int& a : v)if (a == 2)a = 1;
	return is1(v);
}

int n;
string a;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n >> a;
	

	vector<int> v(n);
	rep(i, n) {
		v[i] = a[i] - '0' - 1;
	}

	if (is1(v)) {
		cout << 1 << endl;
	}
	else {
		cout << (is2(v) ? 2 : 0) << endl;
	}

	return 0;
}
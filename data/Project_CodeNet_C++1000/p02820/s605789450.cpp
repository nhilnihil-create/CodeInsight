#include <bit>
#include <bitset>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>


typedef long double ld;
typedef long long ll;

using namespace std;

#define MAXN (1 << 20)

int score[3];
int n, k;
string s;
string c = "rsp";
string w = "201";
int a[MAXN];

int getscore(vector<int> v) {
	v.push_back(3);
	int i = 0;
	int ret = 0;
	while (i < v.size() - 1) {
		int cur = i;
		while (v[i + 1] == v[cur]) {
			i++;
		}
		i++;
		//cerr << ret << " " << i << " " << cur << " " << score[v[cur]] << endl;
		ret += ((i - cur + 1) / 2) * score[v[cur]];
	}
	return ret;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < 3; i++) {
		cin >> score[i];
	}
	cin >> s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if (c[j] == s[i]) {
				a[i] = w[j] - '0';			
			}
		}
	}
	for (int i = 0; i < n; i++) {
//		cerr << a[i];
	}
	//cerr << endl;
	int ret = 0;
	for (int i = 0; i < k; i++) {
		vector<int> cur;
		for (int j = i; j < n; j += k) {
			cur.push_back(a[j]);
		}
		//cerr << ret << endl;
		ret += getscore(cur);
	}
	cout << ret << endl;
	return 0;
}

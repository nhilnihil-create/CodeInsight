#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <cmath>
#include <stdlib.h> 
#include <stdio.h>
#include <iterator>
#include <chrono>
#include <iomanip>
#include <set>
#include <map>
#include <list>
#include <iterator>
#include <deque>
#include <stack>
#include <queue>
#include <fstream>
#include <limits>
#include <unordered_map>
#include <bitset>
#include <numeric>
#include <sstream>
#include <random>
#include <cassert>

using namespace std;
#define ffor(n) for(int i = 0; i < n; i++)
#define fffor(n) for(int j = 0; j < n; j++)
int INF = 1e9 + 7;

int get_rep(int a, vector <int> & rep) {
	while (rep[a] != a) a = rep[a];
	return a;
}

void join(int a, int b, vector <int> & size, vector<int> & rep) {
	a = get_rep(a, rep); b = get_rep(b, rep);
	if (a == b) return;
	if (size[a] > size[b]) swap(a, b); // join a to b
	rep[a] = b;
	size[b] += size[a];
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(0);

	int n, q, a, b;
	cin >> n >> q;
	vector <int> size(n, 1), rep(n);
	for (int i = 0; i < n; i++) rep[i] = i;

	ffor(q) {
		cin >> a >> b;
		a--; b--;
		join(a, b, size, rep);
	}

	int maximum = 0;
	for (auto e : size) maximum = max(maximum, e);
	cout << maximum;
}
	




/*
C:\Users\User\Desktop\comp_programming\final_straw_after_this_im_switching_to_vs_code\final_straw_after_this_im_switching_to_vs_code.cpp
*/
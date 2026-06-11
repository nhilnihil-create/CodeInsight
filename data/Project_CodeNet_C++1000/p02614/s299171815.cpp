
#pragma warning(disable : 26451)
#pragma warning(disable : 26495)

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<stdio.h>
#include<map>
#include<unordered_set>
#include<limits.h>
#include<list>
#include <cassert>
#include<sstream>
#include<bitset>
#include<list>
#include<unordered_map>
#include<unordered_set>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using uint = unsigned int;

int main() {
	int rows, cols, k, all=0, need, cur;
	ll anscnt = 0;
	cin >> rows >> cols >> k;
	vector<vector<int>> g(rows, vector<int>(cols));
	vector<int> rrec(rows, 0), crec(cols, 0);
	for(int r=0;r<rows;++r)
		for (int c = 0; c < cols; ++c)
		{
			g[r][c] = (cin >> ws).get() == '#';
			rrec[r] += g[r][c];
			crec[c] += g[r][c];
			all += g[r][c];
		}
	need = all - k;
	//dfs
	vector<int> rsta(rows), csta(cols);
	auto parse = [&](const ull &dfs)->bool {//rows first
		cur = 0;
		for (int r = 0; r < rows; ++r) {
			rsta[r] = (dfs & (1ULL << r));
			cur += rsta[r] ? rrec[r] : 0;
		}
		for (int c = 0; c < cols; ++c) {
			csta[c] = (dfs & (1ULL << (rows + c)));
			cur += csta[c] ? crec[c] : 0;
		}
		for (int r = 0; r < rows; ++r)
			for (int c = 0; c < cols; ++c)
				if (rsta[r] && csta[c] && g[r][c])
					--cur;
		return cur == need;
	};
	for (ull bits = 0; bits < (1ULL << (cols + rows)); ++bits)
	{
		anscnt += parse(bits);
	}
	cout << anscnt << endl;
}



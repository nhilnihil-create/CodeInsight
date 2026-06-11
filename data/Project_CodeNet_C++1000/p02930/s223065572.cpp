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



int popcount32(unsigned int x) {
	x = x - ((x >> 1) & 0x55555555);
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	x = (x + (x >> 4)) & 0x0F0F0F0F;
	x = x + (x >> 8);
	x = x + (x >> 16);
	return x & 0x0000003F;
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int n;
	cin >> n;
	rep(i, n-1) {
		for (int j = i + 1; j < n; j++) {
			int p = i ^ j;
			int d;
			rep(k, 10) {
				if (p >> k &1) {
					d = k;
					break;
				}
			}

			cout << d + 1;
			if (j + 1 < n)cout << ' ';
		}
		cout << endl;
	}


	return 0;
}
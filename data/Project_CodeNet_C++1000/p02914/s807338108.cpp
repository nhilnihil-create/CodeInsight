#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
const long double eps = 1e-12;
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*2
#define REP(a,b) for(long long a = 0;a < b;++a)
long long cnt[1000];
int main() {
#define int long long
	int n;
	cin >> n;
	vector<long long> inputs;
	REP(i, n) {
		long long a;
		cin >> a;
		inputs.push_back(a);
		REP(q, 61) {
			if (((1LL << q) & a) != 0) {
				cnt[q]++;
			}
		}
	}
	long long tmp_ans = 0;
	REP(q, 61) {
		if (cnt[q] % 2 == 1) {
			tmp_ans += (1LL << q);
			REP(j, n) {
				if (((1LL << q) & inputs[j])) {
					inputs[j] -= 1LL << q;
				}
			}
		}
	}
	long long ans = 0;
	REP(q, n) {
		ans ^= inputs[q];
	}
	long long bobo = 0;
	for (long long q = 60; q >= 0;--q) {
		REP(j, n) {
			if (((1LL << q) & inputs[j])) {
				int ok = 1;
				for (long long t = q + 1; t <= 60; ++t) {
					if (((1LL << t) & inputs[j]) != 0) {
						ok = 0;
						break;
					}
				}
				if (ok == 0) continue;
				for (int t = 0; t < n; ++t) {
					if (t == j) continue;
					if ((1LL << q) & inputs[t]) {
						inputs[t] ^= inputs[j];
					}
				}
				break;
			}
		}
	}
	REP(q, n) {
		bobo ^= inputs[q];
	}
	tmp_ans += bobo + (ans ^ bobo);
	cout << tmp_ans << endl;
}
/*
int n;
string s;
long long gogo[20000];
int solve(int len) {
	long long dying = 1;
	long long gekoa = 1;
	int itr = 0;
	long long now = 0;
	long long aa = 0;
	for (int q = 0; q < s.length(); ++q) {
		now *= 26LL;
		now += s[q] - 'a';
		now %= MAX_MOD;
		aa *= 26LL;
		aa += s[q] - 'a';
		aa %= MOD;
		if (q >= len) {
			now += (MAX_MOD - ((dying * (s[q - len] - 'a') % MAX_MOD))) % MAX_MOD;
			now %= MAX_MOD;
			aa += (MOD - ((gekoa * (s[q - len] - 'a') % MOD))) % MOD;
			aa %= MOD;
		}
		else {
			dying *= 26LL;
			dying %= MAX_MOD;
			gekoa *= 26LL;
			gekoa %= MOD;
		}
		if (q >= len - 1) {
			gogo[itr] = now * MOD + aa;
			itr++;
		}
	}
	set<long long> nya;
	for (int i = itr - len - 1; i >= 0; --i) {
		nya.insert(gogo[i + len]);
		if (nya.find(gogo[i]) != nya.end()) return true;
	}
	return false;
}
int main() {
	cin >> n >> s;
	int bot = 0;
	int top = s.length();
	while (top - bot > 1) {
		int mid = (top + bot) / 2;
		if (solve(mid) == true) {
			bot = mid;
		}
		else top = mid;
	}
	cout << bot << endl;
}

*/
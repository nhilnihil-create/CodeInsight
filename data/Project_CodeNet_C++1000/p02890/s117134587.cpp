//カタラン数を語らん!w

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
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*2
#define REP(a,b) for(long long a = 0;a < b;++a)
vector<int> inputs;
long long ruiseki[400000];
long long ans[400000];
long long cnt[400000];
int main(){
	int n;
	cin >> n;
	REP(i, n) {
		int a;
		cin >> a;
		cnt[a]++;
	}
	REP(i, n) {
		if (cnt[i + 1] != 0) {
			inputs.push_back(cnt[i + 1]);
		}
		cnt[i + 1] = 0;
	}
	REP(i, inputs.size()) {
		cnt[inputs[i]]++;
		ruiseki[inputs[i]] += inputs[i];
	}
	for (int i = 1; i <= n; ++i) {
		ruiseki[i] += ruiseki[i - 1];
		cnt[i] += cnt[i - 1];
	}
	cout << n << endl;
	for (long long i = 2; i <= n; ++i) {
		if (inputs.size() < i) {
			cout << 0 << endl;
		}
		else {
			long long bot = 0;
			long long top = n;
			while (top - bot > 1) {
				long long mid = (top + bot) / 2;
				long long bo = ruiseki[mid] + (cnt[n] - cnt[mid]) * mid;
				if (bo / i >= mid) {
					bot = mid;
				}
				else {
					top = mid;
				}
			}
			cout << bot << endl;
		}
	}
}
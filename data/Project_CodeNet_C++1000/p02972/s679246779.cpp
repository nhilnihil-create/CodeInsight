#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>
#include <new>
#include <typeinfo>
#include <iterator>

typedef long long ll;
typedef unsigned long long ull;
constexpr ll mop = 1000000007;
constexpr ll mop2 = 998244353;

using namespace std;

int main() {
	ll n;
	cin >> n;
	vector<int> aList;
	aList.resize(n + 1);
	vector<int> ballList;
	ballList.resize(n + 1);
	for (ll i = 1; i <= n; i++) {
		cin >> aList[i];
	}
	ll ansM = 0;
	vector<ll> ansList;
	for (ll i = n; i >= 1; i--) {
		ll tmpSum = 0;
		ll now = i;
		while (now <= n) {
			tmpSum += ballList[now];
			now += i;
		}
		if ((tmpSum - aList[i]) % 2 != 0) {
			ansM++;
			ballList[i]++;
			ansList.push_back(i);
		}
	}
	cout << ansM << endl;
	for (ll i = 0; i < ansM; i++) {
		if (i) {
			cout << " ";
		}
		cout << ansList[i];
	}
	cout << endl;
	
} 
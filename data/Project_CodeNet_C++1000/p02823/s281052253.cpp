#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <stack>
#include <chrono>
#include <random>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define ll long long
#define INF 1000000000000000000
#define MOD 1000000007
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;

int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	if ((b - a) % 2 == 0) {
		cout << (b - a) / 2;
	} 
	else {
		if (a - 1 <= n - b) {
			cout << a + (b - a - 1) / 2;
		}
		else {
			cout << n - b + 1 + (n - (a + n - b + 1)) / 2;
		}
	}
}


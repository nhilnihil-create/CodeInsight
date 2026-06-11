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
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	if (a > w / 2 || b > h / 2) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (i % 2 == 0) {
				if (j < a)
					cout << '0';
				else
					cout << '1';
			}
			else {
				if ((i + 1) / 2 <= b) {
					if (j < a)
						cout << '1';
					else
						cout << '0';
				}
				else {
					if (j < a)
						cout << '0';
					else
						cout << '1';
				}
			}			
		}
		cout << '\n';
	}	
}

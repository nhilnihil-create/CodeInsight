#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <math.h> 
#include <iomanip>
#include <string.h>
#include <sstream>
#include <vector>
#include <queue>
#include <utility>  
#include <set>
#include<unordered_set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define PI 3.14159265358979323846264338327950L
#define INF 0x3f3f3f3f
//const int N = 2e5 + 5;
   
int sum(int l, int r) {

	return (l + r)*(r - l + 1) / 2;

}

int gcd(int a, int b) {

	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}

}

 
int f[100001];
 

int Find(int x) {

	if (x == f[x])
		return x;

	return f[x] = Find(f[x]); 

}
const int Mod = 1e9 + 7;

long long fastPower(long long base, long long power) {
	long long result = 1;
	while (power > 0) {
		if (power & 1) { 
			result = result * base % Mod;
		}
		power >>= 1; 
		base = (base * base) % Mod;
	}
	return result;
}
 
int Inv(int x) {
	return fastPower(x, Mod - 2);
}


int nChoosek(int n, int k) {
 
	int ans = 1;

	for (int i = 1; i <= k; ++i) 
		ans = ans * Inv(i) % Mod *(n - i + 1) % Mod;

	return ans % Mod;

}


int arr[200001];

int digit(int n) {

	int cnt = 0;
	
	while (n) {

		n /= 10;
		cnt++;

	}

	return cnt;
}

int binarySearchLessThanOrEqual(int des) {

	int l = 0;
	int r = 1000000000;

	while (l <= r) {

		int mid = (l + r) / 2;

		if (mid > des) {

			r = mid - 1;

		}
		else {
			l = mid + 1;
		}
	}

	return r;

}

vector<vector<int> >v;
 

int32_t main() {

	IOS;

	int n;
	cin >> n;
	v.resize(n);

	vector<pair<int, int>> vp;

	for (int i = 0; i < n - 1; i++) {
		int a, b;

		cin >> a >> b;
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);

		vp.emplace_back(a, b);
	}
 
	int K = 0;
	map<pair<int, int>, int> I;
	vector<int> cs(n, 0); // color of edge between its parent

	vector<int> used(n, 0);
	queue<int> que;
 
	que.push(0);
	used[0] = 1;


	while (!que.empty()) {

		int tmp = que.front();
		que.pop();

		if (v[tmp].size() > K) {
			K = v[tmp].size();
		}

		int curr = 1;

		for (int u : v[tmp]) {

			if (used[u]) {
				continue;
			}

			if (cs[tmp] == curr)
				curr++;

			cs[u] = I[make_pair(u, tmp)] = I[make_pair(tmp, u)] = curr++;
			que.push(u);
			used[u] = 1;
		}

	 

	}
	
	cout << K << endl;

	for (auto c : vp) {
		cout << I[c] << endl;
	}
 


}
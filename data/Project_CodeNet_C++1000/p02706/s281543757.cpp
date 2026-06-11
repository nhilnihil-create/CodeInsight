#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include<vector>
#include<utility>
#include<fstream>
#include<queue>
#include <iomanip>
#include<numeric>
#include<set>
#include<map>
#include<functional>
using namespace std;
#define rep(i, k) for (i = 0; i < k; i++) 
typedef long long ll;
typedef pair<ll, ll> l_l;
int i, j;

ll b, k, n = 0,m, z = 0, x, y, a[200005] = {};
	vector<ll> v,vec;
	string s, t;
int main() {
	cin >> n>>m;
	rep(i, m) {
		cin >> b;
		z += b;
	}
	if (z > n)cout << "-1";
	else cout << n - z;

	return 0;

}

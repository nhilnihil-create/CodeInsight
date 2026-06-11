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
double b,dd=0;
ll  k, n = 0,m, z = 0, x, y, a[200005] = {};
	vector<ll> v,vec;
	string s, t;
int main() {
	cin >> n;
	rep(i,n ) {
		cin >> b;
		dd += (1 / b);
	}
	cout << std::fixed << std::setprecision(10) << 1/dd << endl;

	return 0;

}

#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
//const ll MOD = 1e9 + 7;
const ll MOD = 998244353;




int main() {
	int n, m;
	cin >> n >> m;
	int a = 1;
	int b = 1 + m;
	

	for (int i = 0; i < m-m / 2; i++) {
		cout << a << " " << b << endl;
		a++;
		b--;
		
	}
	a = n - m + 1;
	b = n;

	for (int i = 0; i < m / 2; i++) {
		cout << a << " " << b << endl;
		a++;
		b--;
	}

	
}

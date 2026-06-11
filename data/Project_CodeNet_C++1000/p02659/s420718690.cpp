#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

int main() {
	ll a;
	double b;
	cin >> a >> b;
	ll c;
	c = 100 * b+0.1;
	cout << a * c / 100;
	return 0;
}
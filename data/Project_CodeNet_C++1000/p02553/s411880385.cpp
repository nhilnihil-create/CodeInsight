#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

int main(){
	ll a, b, c, d; cin >> a >> b >> c >> d;
	cout << max({a*c, a*d, b*c, b*d}) << endl;
}
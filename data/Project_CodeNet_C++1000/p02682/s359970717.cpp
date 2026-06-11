#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

int main(){
	ll a, b, c, k; cin >> a >> b >> c >> k;
	if( k <= a + b ) cout << min(k, a) << endl;
	else cout << a-min(c, k-(a+b)) << endl;
}
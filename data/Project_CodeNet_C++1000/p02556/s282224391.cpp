#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

int main(){
	int n; cin >> n; 
	vector<ll> a, b;
	while( n-- ){
		ll x, y; cin >> x >> y;
		a.push_back(x+y);
		b.push_back(x-y);
	}
	cout << max(
		(*max_element( a.begin(), a.end() )) - (*min_element( a.begin(), a.end() )),
		(*max_element( b.begin(), b.end() )) - (*min_element( b.begin(), b.end() ))
	) << endl;
}
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = double;
using pll = pair < ll, ll >;
 
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std :: endl;
}
template < typename Arg1, typename... Args >
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}
#else
#define trace(...)
#endif
 
#define pb push_back
#define mp make_pair
#define fastIo() ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
const int MOD = 1e9 + 7, INF = INT_MAX, N = 1e5 + 10;
 
int main(){
	ll a, b, c, d; cin >> a >> b >> c >> d;
	int a1 = ceil((c * 1.0)/ (b * 1.0));
	int a2 = ceil((a * 1.0) / (d * 1.0));
	if(a1 <= a2) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	// int flag = 0;
	// while(a > 0 && c > 0) {
	// 	if(!flag) {
	// 		c -= b;
	// 		flag = 1;
	// 	} else {
	// 		a -= d;
	// 		flag = 0;
	// 	}
	// 	cout << a  << " " << b << " " << c << " " << d << endl;
	// 	if(c <= 0) break; 
	// 	if(a <= 0) break;
	// }
	// if(a <= 0) {
	// 	cout << "No\n";
	// } else {
	// 	cout << "Yes\n";
	// }
}
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
#define lambdify(x) [&](auto &&...args){ return x(forward<decltype(args)>(args)...); }
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, a, b, c, d;
	string s;
	cin >> n >> a >> b >> c >> d >> s, -- a, -- b, -- c, -- d;
	if(d < c){
		bool ok = false;
		for(auto i = b; i <= min(n - 1, d); ++ i){
			if(s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.'){
				ok = true;
				break;
			}
		}
		if(!ok){
			cout << "No\n";
			return 0;
		}
	}
	for(auto i = a; i < c; ++ i){
		if(s[i] == '#' && s[i + 1] == '#'){
			cout << "No\n";
			return 0;
		}
	}
	for(auto i = b; i < d; ++ i){
		if(s[i] == '#' && s[i + 1] == '#'){
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////
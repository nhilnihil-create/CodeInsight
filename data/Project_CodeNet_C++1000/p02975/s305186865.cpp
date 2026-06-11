#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	map<int, int> a;
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		++ a[x];
	}
	if(int(a.size()) == 1){
		if(!a.begin()->first){
			cout << "Yes";
		}
		else{
			cout << "No";
		}
	}
	else if(n % 3){
		cout << "No";
	}
	else if(int(a.size()) == 2){
		if(!a.begin()->first && a.begin()->second == n / 3){
			cout << "Yes";
		}
		else{
			cout << "No";
		}
	}
	else if(int(a.size()) == 3){
		if(a.begin()->second == n / 3 && a.rbegin()->second == n / 3 && !(a.begin()->first ^ next(a.begin())->first ^ a.rbegin()->first)){
			cout << "Yes";
		}
		else{
			cout << "No";
		}
	}
	else{
		cout << "No";
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////
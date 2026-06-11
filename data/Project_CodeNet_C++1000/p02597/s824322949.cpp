#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);

	int n;
	string s;
	cin >> n >> s;

	vector<int> r, w;

	for(int i = 0; i < n; i++){
		if(s[i] == 'W')
			w.push_back(i);
		else
			r.push_back(i);
	}

	if(w.empty() || r.empty()){
		cout << 0 << endl;
		return 0;
	}

	int p1 = 0, p2 = (int)r.size() - 1, ans = 0;
	while(p1 < w.size() && p2 >= 0 && w[p1] < r[p2]){
		ans++;
		p1++;
		p2--;
	}

	cout << ans << endl;
	
	return 0;
}

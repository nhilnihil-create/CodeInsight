#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define rev(v) reverse(v.begin(), v.end());
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin());
#define io() ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);srand(time(NULL));
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
	io();
	vector<int> v(3);
	cin >> v[0] >> v[1] >> v[2];
	sort(all(v));
	if(v[0] == v[1]){
		cout << (v[1] != v[2] ? "Yes" : "No") << '\n';
	}else if(v[1] == v[2]){
		cout << (v[0] != v[1] ? "Yes" : "No") << '\n';
	}else{
		cout << "No\n";
	}
	return 0;
}
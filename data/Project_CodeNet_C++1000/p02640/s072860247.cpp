#include<bits/stdc++.h>

using namespace std;

#define int long long
#define nl '\n'

#define st first
#define nd second
#define ins insert

#define pb push_back
#define mp make_pair

#define hashmap unordered_map
#define hashset unordered_set

signed main(){
	int x, y; cin >> x >> y;
	bool flag = false;
	for (int i = 0; i <= x; i++){
		if (2*i + 4*(x - i) == y){
			flag = true;
		}
	}
	if (flag) cout << "Yes";
	else cout << "No";
}

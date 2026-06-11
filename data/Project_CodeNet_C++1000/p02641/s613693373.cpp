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
	int x, n; cin >> x >> n; hashset<int> s;
	for (int i = 0; i < n; i++){
		int j; cin >> j; s.ins(j);
	}
	int c1 = x, c2 = x;
	while (s.count(c1) == 1){
		c1--;
	}
	while (s.count(c2) == 1){
		c2++;
	}
	if (abs(x - c1) <= abs(x - c2)){
		cout << c1;
	} else cout << c2;
}

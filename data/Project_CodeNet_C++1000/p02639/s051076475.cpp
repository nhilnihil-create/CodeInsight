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
	vector<int> v(5); int ans;
	for (int i = 0; i < 5; i++){
		cin >> v[i];
		if (v[i] == 0){
			ans = i + 1;
		}
	}
	cout << ans;
}

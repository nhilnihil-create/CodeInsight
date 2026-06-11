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
	int n; cin >> n; hashset<string> ans;
	for (int i = 0; i < n; i++){
		string s; cin >> s; ans.ins(s);
	}
	cout << ans.size();
}

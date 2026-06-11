#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
const int INF = 1e9;
const ll mod = 1e9 + 7;

void setup(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif	
}

int main(){
setup();
	ll T = 1;
	//cin >> T;	
	while (T--){
		string s; cin >> s;
		ll tot = 0;
		for (int i = 0; i<s.size(); i++){
			ll num = (int) s[i] - '0';
			tot+=num;
		}
		if (tot%9 == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
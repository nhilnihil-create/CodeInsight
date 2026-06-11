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
		ll x,k,d;
		cin >> x >> k >> d;
		ll diff = llabs(x);
		ll ex = diff%d;
		if (k < (diff/d)){
			cout << diff-(k*d);
			return 0;
		}
		if ((diff/d)%2 != k%2) cout << d-ex << endl;
		else cout << ex << endl;

	}
}
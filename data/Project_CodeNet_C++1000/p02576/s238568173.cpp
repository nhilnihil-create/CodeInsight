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
		ll n, x, t;
		cin >> n >> x >> t;
		ll ex = 0; 
		if (n%x != 0) ex = t;
		cout << (n/x)*t + ex << endl;
	}
}
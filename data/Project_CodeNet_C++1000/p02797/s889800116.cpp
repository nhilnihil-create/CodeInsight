#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main(){
	ll n, k, s; cin >> n >> k >> s;
		for(ll i = 0; i < n; ++i){
			if(i < k)
				cout << s << " ";
			else cout << (s + ll(1)) % ll(1000000000) <<" ";
		}
	return 0;
}

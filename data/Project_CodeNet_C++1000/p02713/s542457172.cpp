#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rot(s, k) rotate(s.begin(), s.begin()+ s.size()-(k%s.size()), s.end()); 

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	ll total = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			for(int k=1; k<=n; ++k){
				total += __gcd(i,__gcd(j,k));
			}
		}
	}

	cout << total << "\n";


}

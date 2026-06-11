#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

main(){
	ll n;
	cin >> n;

	ll ans = 0;
	for(ll i=1;i<=n;i++){
		ans += (n/i)*((n/i)+1)*i/2;
	}

	cout << ans << endl;

	return 0;
}

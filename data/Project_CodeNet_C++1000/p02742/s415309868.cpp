#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

const ll mod = 1e9 + 7;


main(){
	ll a,b;
	cin >> a >> b;

	ll t1 = (b+1)/2;
	ll t2 = b/2;
	ll u1 = (a+1)/2;
	ll u2 = a/2;

	ll ans = t1*u1 + t2*u2;

	if(a==1 || b==1) ans = 1;

	cout << ans << endl;

	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll A;
	double B;
	cin >> A >> B;
	ll ans = (A* (ll)(B*100+0.1) ) / 100;
	cout << ans << endl;
	return 0;

}

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll; 


int main(){
	ll n, a, b;

	cin >> n >> a >> b;

	ll ans = n/(a+b);
	ans *= a;
	if((n%(a+b))>a) ans += a;
	else ans += n%(a+b);

	cout << ans << endl;

	return 0;
}

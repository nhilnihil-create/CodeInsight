#include <iostream>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
using namespace std;

int a, b, c, k, ans;
int main() {
	cin >> a >> b >> c >> k;
	
	ans += min(a,k);
	k -= min(a,k);
	
	if(k <= 0){
		cout << ans << endl;
		return 0;
	}
	
	k -= min(b,k);
	
	if(k <= 0){
		cout << ans << endl;
		return 0;
	}
	
	ans -= min(c,k);
	k -= min(c,k);
	
	cout << ans << endl;

    return 0;
}
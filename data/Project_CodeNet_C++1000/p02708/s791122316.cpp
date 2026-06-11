#include <iostream>
typedef long long ll;
using namespace std;

ll mod=1000000007;

int main() {
	ll N, K;
	cin >> N >> K;
	ll ans=0, now=0;
	for(ll i=0; i<=N; ++i){
	    (now += (N-i*2+mod)%mod) %= mod;
	    if(i+1>=K) (ans += now+1) %= mod;
	}
	cout << ans << endl;
	return 0;
}

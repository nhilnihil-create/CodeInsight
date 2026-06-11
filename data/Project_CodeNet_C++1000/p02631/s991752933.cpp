#include <cstdio>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
using namespace std;

ll N, a[200010];
int main() {
	scanf("%lld", &N);
	rep(i, 0, N) scanf("%lld", &a[i]);

	ll AllXor = a[0];
	rep(i, 1, N) AllXor ^= a[i];

	rep(i, 0, N) {
		printf("%lld", AllXor ^ a[i]);
		if(i != N-1) printf(" ");
	}
	printf("\n");
    return 0;
}

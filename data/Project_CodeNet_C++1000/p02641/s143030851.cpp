#include <iostream>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
using namespace std;

int x, n;
bool p[101];
int main() {
	cin >> x >> n;
	rep(i, 0, n) {
		int tmp; cin >> tmp;
		p[tmp] = true;
	}

	int ans = x, min = 1000;
	rep(i, 0, 102){
		if(p[i]) continue;
		if(min > abs(x-i)){
			min = x-i;
			ans = i;
		}
	}
	cout << ans << endl;
    return 0;
}

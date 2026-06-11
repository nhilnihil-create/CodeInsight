#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
#define INF 1e9
#define DEBUG(x) cout<<"debug: "<<x<<endl
using namespace std;

int n;
int main() {
	cin >> n;
	ll ans = 0;
	rep(i, 1, n+1){
		if(i%3 == 0 || i%5 == 0) continue;
		ans += i;
	}
	cout << ans << endl;
	return 0;
}

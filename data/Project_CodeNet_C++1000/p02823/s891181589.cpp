#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define be(v) (v).begin(), (v).end()
#define dcout cout << fixed << setprecision(20) 
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int main() {
	ll k,a,b;
	cin >> k >> a >> b;
	if((b-a)%2==0) {
		cout << min((b-a)/2,min(b-1,k-a)) << endl;
		return 0;
	}
	if(a==1||b==k) {
		cout << (b-a+1)/2 << endl;
		return 0;
	}
	ll n = a-1;
	ll m = k-b;
	cout << min(n,m)+1+((b-a-1)/2) << endl;
}
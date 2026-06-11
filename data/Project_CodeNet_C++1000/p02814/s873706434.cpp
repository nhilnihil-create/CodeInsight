#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i,n) cin >> a[i], a[i]/=2;
	int cnt = 0;

	while(a[0]%2==0) {
		rep(i,n){
			if(a[i]&1){
				cout << 0 << endl;
				return 0;
			}
			a[i]/=2;
		}
		cnt++;
	}
	srep(i,1,n) if(a[i]%2==0){
		cout << 0 << endl;
		return 0;
	}

	ll lcm = 1;
	rep(i,cnt) lcm*=2; 
	rep(i,n){
		lcm = lcm * a[i] / __gcd(lcm, (ll)a[i]);
		if(lcm > m) {
			cout << 0 << endl;
			return 0;
		}
	}

	ll ans = 1+(m-lcm)/(2*lcm);
	cout << ans << endl;
}
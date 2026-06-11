#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin(), v.end()
bool chmin(ll & a, ll  b) { if (b < a) { a = b; return 1; } return 0; }
bool chmax(ll & a, ll b) { if (b > a) { a = b; return 1; } return 0; }
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX_N=500010;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans;
int main() {
    cin>>n;
	string s;
	vl B;
	vector<string> A;
	rep(i,n){
cin>>s>>a;
A.push_back(s);
B.push_back(a);
	}
		cin>>s;
		a=0;
	rep(i,n){
		ans+=a*B[i];
		if(A[i]==s)a++;
	}

	cout<<ans<<endl;
}
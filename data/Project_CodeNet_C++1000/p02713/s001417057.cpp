#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define rrep(i,j,n) for(ll i = (ll)(j); i <= (ll)(n); i++)
#define mrep(i,n) for (ll i = (ll)(n-1); i >= 0; i--)
#define be(v) (v).begin(), (v).end()
#define dcout cout << fixed << setprecision(20) 
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int gcd(int a,int b) { 

    if(a>b) swap(a,b); 

    if(a%b==0) return b;        //最大公約数 

    else return gcd(a,b); 

} 

int main() {
	ll n; cin >> n;
	ll ans=0;
	rrep(i,1,n)rrep(j,1,n)rrep(k,1,n) {
		ans+=gcd(i,gcd(j,k));
	}
	cout << ans << endl;
}
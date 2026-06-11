#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(long long i=0; i<(long long)(n); i++)
#define REP(i, k, n) for(long long i=(long long)(k); i<(long long)(n); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define PQ(T) priority_queue<T>
#define PQS(T) priority_queue<T, vector<T>, greater<T> >
#define deci cout << fixed << setprecision(15);
typedef long long ll;
const ll inf = 1020304050607080910;
const int mod = 1000000007;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T> bool chmin(T&x,T y){if(x>y){x=y;return true;}return false;}
template<class T> bool chmax(T&x,T y){if(x<y){x=y;return true;}return false;}
ll gcd(ll x,ll y){if(x>y)swap(x, y);while(x!=0){y%=x;swap(x, y);}return y;}
ll mpow(ll x,ll r){if(r==0)return 1;if(r%2==1){return x*mpow(x,r-1)%mod;}else{ll aa=mpow(x,r/2);return aa*aa%mod;}}

int main(){
	string s; cin >> s;
	vector<int> a;
	int c = 0;
	rep(i, s.size()){
		if(i==0) c++;
		else{
			if(s[i] != s[i-1]){ a.pb(c); c=1; }
			else c++;
		}
	}
	a.pb(c);
	ll ans = 0;
	if(s[0] == '<'){
		rep(i, a.size()){
			ans += (ll)(a[i]-1)*a[i]/2;
			if(i%2==0){
				if(i+1==a.size()){
					ans += a[i];
				}else{
					ans += max(a[i], a[i+1]);
				}
			}
		}
	}else{
		rep(i, a.size()){
			ans += (ll)(a[i]-1)*a[i]/2;
			if(i%2==0){
				if(i==0) ans += a[i];
				else ans += max(a[i], a[i-1]);
			}
		}
		if(a.size()%2==0) ans += a[a.size()-1];
	}
	cout << ans << endl;
	return 0;
}


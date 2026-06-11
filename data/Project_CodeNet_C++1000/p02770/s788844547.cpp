#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rrep(i, n) for(int i=((int)(n)-1); i>=0; i--)
#define REP(i, k, n) for(int i=(int)(k); i<(int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define PQ(T) priority_queue<T>
#define PQS(T) priority_queue<T, vector<T>, greater<T> >
#define deci cout << fixed << setprecision(15);
typedef long long ll;
const int INF = INT_MAX;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T> bool chmin(T&x,T y){if(x>y){x=y;return true;}return false;}
template<class T> bool chmax(T&x,T y){if(x<y){x=y;return true;}return false;}
ll gcd(ll x, ll y){ if(x>y) swap(x, y);while(x!=0){ y%=x; swap(x, y); }return y; }
ll mpow(ll x, ll r){if(r==0) return 1;if(r%2==1){ return x*mpow(x, r-1)%mod; }else{ ll aa = mpow(x, r/2); return aa*aa%mod; }}

int main(){
	int k, q; cin >> k >> q;
	int d[k];
	rep(i, k) cin >> d[i];
	rep(i, q){
		ll n, x, m; cin >> n >> x >> m;
		ll sum = 0, cnt = 0;
		n--;
		rep(j, k){
			if(d[j] % m != 0) cnt++;
			sum += d[j] % m;
		}
		sum *= n/k;
		cnt *= n/k;
		rep(j, n % k){
			if(d[j] % m != 0) cnt++;
			sum += d[j] % m;
		}
		sum += x % m;
		cout << cnt - sum/m << endl;
	}
	return 0;
}
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
	int N; cin >> N;
	int a[N], f = 0;
	rep(i, N){
		char c; cin >> c;
		a[i] = c - '0';
		f += a[i]*(((N-1)&i)==i);
	}
	if(f%2) cout << 1 << endl;
	else{
		rep(i, N-1){
			if(a[i]%2 != a[i+1]%2){
				cout << 0 << endl;
				return 0;
			}
			f += abs(a[i+1]-a[i])/2*(((N-2)&i)==i);
		}
		if(f%2) cout << 2 << endl;
		else cout << 0 << endl;
	}
	return 0;
}
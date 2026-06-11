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
const ll mod = 1000000007;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T> bool chmin(T&x,T y){if(x>y){x=y;return true;}return false;}
template<class T> bool chmax(T&x,T y){if(x<y){x=y;return true;}return false;}
ll gcd(ll x,ll y){if(x>y)swap(x, y);while(x!=0){y%=x;swap(x, y);}return y;}
ll mpow(ll x,ll r){if(r==0)return 1;if(r%2==1){return x*mpow(x,r-1)%mod;}else{ll aa=mpow(x,r/2);return aa*aa%mod;}}

int main(){
	ll N, ans = 0; cin >> N;
	ll A[N+1], L[N+1], R[N+1];
	rep(i, N+1){ cin >> A[i]; ans+=A[i]; }
	if(N==0){
		if(A[0] == 1) cout << 1 << endl;
		else cout << -1 << endl;
		return 0;
	}
	L[0] = R[0] = 1;
	if(A[0] != 0){
		cout << -1 << endl;
		return 0;
	}
	rep(i, N){
		L[i+1] = L[i] - A[i+1], R[i+1] = 2*R[i] - A[i+1];
		if(R[i+1] > inf) R[i+1] = inf;
		if(R[i+1]<0){
			cout << -1 << endl;
			return 0;
		}
		if(L[i+1]<0) L[i+1] = 0;
	}
	if(L[N]!=0){
		cout << -1 << endl;
		return 0;
	}
	ll pre = 0;
	for(int i=N-1; i>=0; i--){
		if(pre+A[i+1] < R[i]){ ans += pre+A[i+1]; pre+=A[i+1]; }
		else{ ans += R[i]; pre = R[i]; }
	}
	cout << ans << endl;
	return 0;
}

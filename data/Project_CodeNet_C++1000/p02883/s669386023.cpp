#include <bits/stdc++.h>
typedef long long ll;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP2(i, a, b) for(int i = a;i <= b;i++)
#define REPR(i, a, b) for(int i = a; i >= b; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define PI 3.14159265358979323846
#define vi vector<int>
#define vll vector<ll>
#define vi2 vector<vector<int>>
#define eb emplace_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
using P = pair<ll,ll>;
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1}, dy[]{1, 0, -1, 0, -1, 1, -1, 1};
#define INT(name) int name;cin >> name;
#define VEC(type,name,n) vector<type> name(n);REP(i,n) cin >> name[i];

template<class T> inline bool chmin(T& a, T b) {
	  if (a > b) {
		      a = b;
		          return true;
			    }
	    return false;
}
template<class T> inline bool chmax(T& a, T b) {
	  if (a < b) {
		      a = b;
		          return true;
			    }
	    return false;
}

bool f(vector<ll> A,vector<ll> F,ll x,ll K){
	ll cnt = 0;
	REP(i,sz(A)){
		if(A[i]*F[i]>x){
			cnt+=A[i]-x/F[i];
		}
	}

	return cnt<=K;
}

int main()
{
	ll N,K;
	cin >> N >> K;
	VEC(ll,A,N);
	VEC(ll,F,N);
	sort(ALL(A));
	sort(ALL(F));
	reverse(ALL(F));

	ll ok=1000000000000;
	ll ng=-1;
	while(abs(ok-ng)>1){
		ll mid=(ok+ng)/2;
		if(f(A,F,mid,K)){
			ok=mid;
		}else{
			ng=mid;
		}
	}

	cout << ok << endl;
}

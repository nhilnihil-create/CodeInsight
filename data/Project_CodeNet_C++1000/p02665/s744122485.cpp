#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

template<class A, size_t N, class T> void Fill(A (&a)[N], const T &v){ fill( (T*)a, (T*)(a+N), v ); }

template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"; return os;}
template<class T,size_t n> ostream& operator<<(ostream &os, const array<T,n> &t) {os<<"{"; rep(i,n) {os<<t[i]<<",";} os<<"}"; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

const ll INF = 1e9+7;


int main(){
	ios_base::sync_with_stdio(false);
	ll N, ans=0;
	ll A[100005];

	cin >> N;
	N++;
	rep(i,N) cin >> A[i];

	ll sum[100005] = {};
	rrep(i,N) sum[i] = sum[i+1] + A[i];

	ll cur = 1;
	rep(i,N){
		ans += cur;
		cur -= A[i];
		if(cur < 0 || sum[i+1] < cur){
			ans = -1;
			break;
		}
		cur = min(cur * 2, sum[i+1]);
	}

	cout << ans << endl;

	return 0;
}
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;
 
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define Fixed fixed << setprecision(12)
#define int int64_t
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int mod1 = 1e9+7; 
constexpr int mod2 = 998244353;
 
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
 
template <class T> using min_heap = priority_queue<T,vector<T>,greater<T> >;
template <class T> using max_heap = priority_queue<T>;
template <class A, class B> using umap = unordered_map<A,B>;
  
inline int updiv(int a,int b){ return (a + b - 1) / b; }
 
constexpr int dx[] = {1,0,-1,0,1,1,-1,-1};
constexpr int dy[] = {0,-1,0,1,1,-1,-1,1};


signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> a(n+1);
	vector<vector<int> > bits(n+1, vector<int>(62));

	reps(i,n){
		cin >> a[i];
		bits[i] = bits[i-1];
		rep(j,62){
			if(1LL << j & a[i]){
				bits[i][j]++;
			}
		}
	}

	int res = 0;

	reps(i,n-1){
		rep(j,62){
			if(1LL << j & a[i]){
				(res += (1LL << j) % mod1 * ((n-i) - (bits[n][j] - bits[i][j])) % mod1) %= mod1;
			}else{
				(res += (1LL << j) % mod1 * (bits[n][j] - bits[i][j]) % mod1) %= mod1;
			}
		}
	}

	cout << res << '\n';

	return 0;
}

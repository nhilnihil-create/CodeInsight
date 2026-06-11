#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define print(x)cout<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;

map<int, int> M;

int main() {
	int N; cin >> N;
	vi a(N);
 
	bool allzero = true;
	bool zero = false;
 
	rep(i, N) {
		cin >> a[i];
		++M[a[i]];
 
		if (a[i] != 0) {
			allzero = false;
		} else {
			zero = true;
		}
	}
 
	bool ok = false;
 
	if (allzero) {
		puts("Yes");
		return 0;
	}
 
	if (N % 3 == 0) {
		int num = N / 3;
 
		if (zero) {
			int x = -1;
			rep(i, N) {
				if (a[i] != 0) {
					x = a[i];
				}
			}
			if (M[x] == num * 2 && M[0] == num) {
				ok = true;
			}
		} else {
			for (int i = 1; i < N; ++i) {
				if (a[i] != a[0]) {
					int x = a[0], y = a[i], z = x ^ y;
					if (M.count(z)) {
						if (M[x] == num && M[y] == num && M[z] == num) {
							ok = true;
						}
					}
				}
			}
		}
	}
 
	puts(ok ? "Yes" : "No");
 
	return 0;
}
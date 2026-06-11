#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,n) for(int i = 1; i <= n; i++)
#define rrep(i,n) for(int i = n-1; i >= 0; i--)
#define rreps(i,n) for(int i = n; i >= 1; i--)
#define co(x) cout << x <<endl
#define cs(x) cout << x <<" "
#define cer(x) cerr << x <<endl
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define ERASE(x,val) x.erase(remove(ALL(x), val), x.end())
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll mod = 1e9 + 7;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }

int main()
{
	int n, k; cin >> n >> k;
	int ans;
	if (k == 1)ans = 0;
	else ans = n - k;
	co(ans);
	return 0;
}

#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	rep(ki, k){
		vector<int> b(n+1);
		rep(i,n){
			int l = max(0,i-a[i]);
			int r = min(i+a[i]+1, n);
			b[l]++; b[r]--;
		}
		rep(i,n) b[i+1] += b[i];
		b.pop_back();
		if (a==b) break;
		a = b;
	}
	rep(i,n) cout << a[i] << endl;
}

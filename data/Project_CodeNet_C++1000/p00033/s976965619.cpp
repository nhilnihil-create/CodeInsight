#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repb(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define int long long
#define fi first
#define se second
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

signed main(){
	int n;
	cin >> n;
	rep(x, 0, n) {
		vi d(10);
		rep(i, 0, 10) {
			cin >> d[i];
		}
		int t1 = 0, t2 = 0;
		bool ans = true;
		rep(i, 0, 10) {
			if (t1 < d[i]) t1 = d[i];
			else if (t2 < d[i]) t2 = d[i];
			else ans = false;
		}
		cout << (ans ? "YES" : "NO") << endl;
	}
}
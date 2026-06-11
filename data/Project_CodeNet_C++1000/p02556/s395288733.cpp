#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pl = pair<ll,ll>;
using pi = pair<int,int>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;
signed main(){
	//cout << fixed << setprecision(10);
    int n; cin >> n;
    vl a(n),b(n);
    rep(i,0,n){
        int x,y; cin >> x >> y;
        a[i] = x + y;
        b[i] = x - y;
    }
    sort(all(a));
    sort(all(b));
    cout << max(a[n-1] - a[0] , b[n-1] - b[0]) << endl;

	return 0;
}
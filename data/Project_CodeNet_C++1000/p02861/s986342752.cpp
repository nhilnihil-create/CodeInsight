#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, vector<ll>> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<double> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    vector<int> v(n);
	rep(i,n) v[i] = i;
    double ans = 0, div = 0;
	do{
		double dist = 0;
        rep(i,n-1){
            dist += sqrt((x[v[i]]-x[v[i+1]])*(x[v[i]]-x[v[i+1]]) + (y[v[i]]-y[v[i+1]])*(y[v[i]]-y[v[i+1]]));
        }
        ans += dist;
        div += 1;
	} while(next_permutation(v.begin(), v.end()));
    ans /= div;
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}

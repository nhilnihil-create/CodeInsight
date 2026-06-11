#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
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
int main(){
    ll h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (ll i = 0; i < h; i++) cin >> grid[i];
    vector<vector<ll>> left(h, (vector<ll>(w, 0))), right(h, (vector<ll>(w, 0))), up(h, (vector<ll>(w, 0))), down(h, (vector<ll>(w, 0)));
    for (ll i = 0; i < h;i++){
        for (ll j = 0; j < w;j++){
            if (grid[i][j] == '#') left[i][j] = 0;
			else if(j>0)
                left[i][j] = left[i][j - 1] + 1;
			else
                left[i][j] = 1;
        }
    }
    for (ll i = 0; i < h;i++){
        for (ll j = w-1; j >=0;j--){
            if (grid[i][j] == '#') right[i][j] = 0;
            else if(j<w-1)
                right[i][j] = right[i][j + 1] + 1;
            else
                right[i][j] = 1;
        }
    }
    for (ll j = 0; j < w;j++){
        for (ll i = 0; i < h;i++){
			if(grid[i][j]=='#')up[i][j]=0;
			else if(i>0)
                up[i][j] = up[i - 1][j] + 1;
			else
                up[i][j] = 1;
        }
    }
    for (ll j = 0; j < w;j++){
        for (ll i = h-1; i >= 0;i--){
			if(grid[i][j]=='#')down[i][j]=0;
			else if(i<h-1)
                down[i][j] = down[i + 1][j] + 1;
            else
                down[i][j] = 1;
        }
    }
    ll ans = 0;
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w;j++){
            chmax(ans, left[i][j] + right[i][j] + up[i][j] + down[i][j]);
        }
    }
    cout << ans - 3 << endl;
}
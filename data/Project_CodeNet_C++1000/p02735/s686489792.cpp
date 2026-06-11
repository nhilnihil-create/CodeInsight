#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define P pair<ll, ll>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((int)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;

void print(Vl v){
    rep(i, 0, sz(v)){
        if(i) cout << " ";
        cout << v[i];
    }
    cout << endl;
}

////////////////////////////////////////////////////////

ll dp[105][105];

int main() {
	ll H, W; cin >> H >> W;
	Vs s(H);
	rep(i, 0, H) cin >> s[i];

	rep(i, 0, 101) rep(j, 0, 101) dp[i][j] = INF;

	if(s[0][0] == '#') dp[0][0] = 1;
	else dp[0][0] = 0;

	rep(h, 0, H) rep(w, 0, W) {
		if(w-1>=0){
			if(s[h][w] == s[h][w-1]) chmin(dp[h][w], dp[h][w-1]);
			if(s[h][w] == '#' && s[h][w-1] == '.') chmin(dp[h][w], dp[h][w-1]+1);
		}
		if(h-1>=0){	
			if(s[h][w] == s[h-1][w]) chmin(dp[h][w], dp[h-1][w]);
			if(s[h][w] == '#' && s[h-1][w] == '.') chmin(dp[h][w], dp[h-1][w]+1);
		}
		if(s[h][w] == '.'){
			if(w-1>=0) chmin(dp[h][w], dp[h][w-1]);
			if(h-1>=0) chmin(dp[h][w], dp[h-1][w]);
		}
	}

	// rep(h, 0, H){
	// 	rep(w, 0, W){
	// 		cout << dp[h][w] << " ";
	// 	}
	// 	cout << endl;
	// }

	co(dp[H-1][W-1]);

    return 0;
}

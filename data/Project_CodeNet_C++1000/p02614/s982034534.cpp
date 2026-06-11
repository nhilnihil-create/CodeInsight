#include <algorithm>
#include <iostream>
#include <vector>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
using namespace std;

int H, W, k, ans;
vector<string> field(6);

int main() {
	cin >> H >> W >> k;
	rep(i, 0, H) cin >> field[i];

	rep(bit1, 0, 1 << H) rep(bit2, 0, 1 << W){
		int count = 0;
		rep(i, 0, H) rep(j, 0, W){
			if(bit1>>i & 1 || bit2>>j & 1) continue;
			if(field[i][j] == '#') count++;
		}
		if(count == k) ans++;
	}

	cout << ans << endl;
    return 0;
}

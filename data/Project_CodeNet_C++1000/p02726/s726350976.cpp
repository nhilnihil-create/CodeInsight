#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    int n, x, y;
    cin >> n >> x >> y;
    --x; --y;
    vector<int> ans(n, 0);
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            int dist = j - i;
            chmin(dist, abs(i-x) + 1 + abs(y-j));
            chmin(dist, abs(i-y) + 1 + abs(x-j));
            ++ans[dist];
        }
    }
    for(int i = 1; i < n; ++i){
        cout << ans[i] << endl;
    }
	return 0;
}
#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int to[65][200005];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    int n;
    ll k;
    cin >> n >> k;
    rep(i,n){
        cin >> to[0][i];
        --to[0][i];
    }
    rep(i,59)rep(j,n) to[i+1][j] = to[i][to[i][j]];
    int cur = 0;
    for(int i = 59; i >= 0; --i){
        ll tmp = 1LL << i;
        if(tmp <= k){
            cur = to[i][cur];
            k -= tmp;
        }
    }
    ++cur;
    cout << cur << endl;
	return 0;
}
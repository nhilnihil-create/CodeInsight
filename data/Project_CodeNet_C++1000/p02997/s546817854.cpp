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
    int n, k;
    cin >> n >> k;
    int m = (n-1)*(n-2)/2;
    if(k > m){
        cout << -1 << endl;
        return 0;
    }
    cout << n-1 + m-k << endl;
    for(int i = 2; i <= n; ++i) cout << 1 << " " << i << endl;
    int x = 2, y = 3;
    rep(i,m-k){
        if(y > n){
            ++x;
            y = x + 1;
        }
        cout << x << " " << y << endl;
        ++y;
    }
	return 0;
}
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
    int m, d;
    cin >> m >> d;
    int ans = 0;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= d; ++j){
            int d1 = j%10;
            int d10 = j/10;
            if(d1 >= 2 && d10 >= 2 && d1 * d10 == i) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}

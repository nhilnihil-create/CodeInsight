#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<string>
using namespace std;
typedef long long ll;
//ll mod = 1e9+7;
ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    vector<int> d(n);
    int max_d = 0;
    bool flg = 0;
    rep(i, n) {
        int tmp_d;
        cin >> tmp_d;
        if ( i == 0 && tmp_d != 0 ) {
            flg = 1;
        }
        ++d[tmp_d];
        max_d = max(max_d, tmp_d);
    }
    if ( flg || d[0] != 1 ) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    for ( int i = 1; i <= max_d; ++i ) {
        int loop_num = d[i];
        while(1) {
            if ( loop_num == 0 ) {
                break;
            }
            ans = ans * d[i-1] % mod;
            --loop_num;
        }
    }
    cout << ans << endl;
    return 0;
}

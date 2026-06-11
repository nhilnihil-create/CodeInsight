#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
// #define debug(a) cout << "["; rep(i,a.size()) cout << a[i] << ", "; cout<<"]"<< endl;

const ll mod = 1000000007;

int main() {
    int n,m; cin >> n >> m;
    vector<int> memo(n+1);
    vector<int> ans(n+1);
    rep(i,m){
        int a; cin >> a;
        memo.at(a) = 1;
    }
    rep(i,n+1){
        if(i==0){
            ans.at(i) = 1;
        } else if(i == 1){
            if(memo.at(i) != 1){
                ans.at(i) = 1;
            }
        } else {
            if(memo.at(i) != 1){
                ans.at(i) = (ans.at(i - 1) + ans.at(i - 2)) % mod;
            }
        }
    }
    cout << ans.at(n) << endl;

    return 0;
}

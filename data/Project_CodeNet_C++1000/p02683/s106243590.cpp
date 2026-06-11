#include<bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define MAX_ANS 123456789

signed main(){
    int n, m, x;
    cin >> n >> m >> x;
    vi c(n);
    vector<vi> a(n, vi(m));
    bool isOK = false;
    int ans = MAX_ANS;

    rep(i, n){
        cin >> c[i];
        rep(j, m){
            cin >> a[i][j];
        }
    }

    /* どの本を取るかビット全探索 */
    for(int bits = 0; bits < (1<<n); bits++){
        bool can_do = true;
        vi tmp_a(m);
        int tmp = 0;
        for(int i = 0; i < n; i++){
            if((bits>>i) & 1){
                /* cout << i << "冊目 ";  */
                rep(j, m) tmp_a[j] += a[i][j];
                tmp += c[i];
            }
        }
        rep(i, m){
            if(tmp_a[i] < x) can_do = false;
        }

        if(can_do){
            isOK = true;
            ans = min(ans, tmp);
        }
    }

    if(ans == MAX_ANS){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

}
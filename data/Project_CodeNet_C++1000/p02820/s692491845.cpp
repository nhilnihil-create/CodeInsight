#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


int main(){
    int n, k;
    cin >> n >> k;
    int r, s, p;
    cin >> r >> s >> p;
    string t;
    cin >> t;
    ll ans = 0;

    rep(j, k){
        char c = 'x';
        for(int i = j; i < n; i += k){
            if (i == j){
                if (t[i] == 'r') c = 'p', ans += p;
                else if (t[i] == 'p') c = 's', ans += s;
                else if (t[i] == 's') c = 'r', ans += r;
            }
            else{
                if (t[i] == 'r' && c == 'p') { //勝ちの手が出せない時
                    if (i+k < n && t[i+k] == 'r') c = 's';
                    else if (i+k < n && t[i+k] == 'p') c = 'r';
                    else if (i+k < n && t[i+k] == 's') c = 's';
                }
                else if (t[i] == 'r') c = 'p', ans += p;
                
                if (t[i] == 'p' && c == 's') { //勝ちの手が出せない時
                    if (i+k < n && t[i+k] == 'r') c = 'r';
                    else if (i+k < n && t[i+k] == 'p') c = 'r';
                    else if (i+k < n && t[i+k] == 's') c = 'p';
                }
                else if (t[i] == 'p') c = 's', ans += s;
                
                if (t[i] == 's' && c == 'r') { //勝ちの手が出せない時
                    if (i+k < n && t[i+k] == 'r') c = 's';
                    else if (i+k < n && t[i+k] == 'p') c = 'p';
                    else if (i+k < n && t[i+k] == 's') c = 'p';
                }
                else if (t[i] == 's') c = 'r', ans += r;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;

    ll r,g,b;
    r = g = b = 0;
    rep(i,N) {
        if (S[i]=='R') r++;
        else if (S[i]=='G') g++;
        else if (S[i]=='B') b++;
    }
    ll ans = r*g*b;

    rep(i,N) {
        rep(j,N) {
            if (i-j<0 || i+j>=N) continue;
            else {
                if (S[i]!=S[i-j] && S[i]!=S[i+j] && S[i-j]!=S[i+j]) ans--;
            }
        }
    }
    cout << ans << endl;
}
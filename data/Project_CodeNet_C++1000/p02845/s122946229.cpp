#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> color(3,0);
    ll ans = 1;
    rep(i,n){
        int cnt = 0;
        rep(j,3){
            if(a[i] == color[j]) cnt ++;
        }
        ans *= cnt;
        rep(j,3){
            if(a[i] == color[j]){
                color[j] ++;
                break;
            }
        }
        
        if(ans >= MOD) ans %= MOD;
    }
    cout << ans << endl;

    return 0;  
}
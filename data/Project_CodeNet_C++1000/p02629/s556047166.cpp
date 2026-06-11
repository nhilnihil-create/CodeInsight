/*    created: 09.08.2020 22:41:29    */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;
const ll MOD = 1000000007;
const ll MX = 0; //最大値

#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define PB push_back
#define F first
#define S second

int main(){
    ll n; cin >> n;
    string s = "abcdefghijklmnopqrstuvwxyz", ans = "";

    while(true){
        n--;
        if(n < 26) {
            ans.PB(s[n]);
            reverse(ALL(ans));
            cout << ans << endl;
            return 0;
        }
        ll tmp = n % 26; n /= 26;
        ans.PB(s[tmp]);
    }
}
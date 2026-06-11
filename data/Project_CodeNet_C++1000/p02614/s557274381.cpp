/*    created: 17.07.2020 01:31:48    */

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

ll h, w, k, ans = 0;
vector<int> A;

int main(){
    cin >> h >> w >> k;
    vector<string> c(h);
    rep(i, h) cin >> c[i];

    for(int i = 0; i < (1 << h); i++){
        for(int j = 0; j < (1 << w); j++){
            ll cnt = 0;
            for (int a = 0; a < h; a++){
                for (int b = 0; b < w; b++){
                    if (i&(1 << a) || j&(1 << b)) continue;
                    if (c[a][b] == '#') cnt++;
                }
            }
            if(cnt == k) ans++;
        }
    }
    cout << ans << endl;
}
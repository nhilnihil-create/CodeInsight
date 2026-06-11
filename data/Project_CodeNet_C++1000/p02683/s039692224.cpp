#include <bits/stdc++.h>
#include <queue>
#include <string>
#include <algorithm>

//#include <atcoder/all>

using namespace std;
//using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define repr1(i, n) for (int i = n; i > 0; i--)
#define FOR(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;
const ll MOD = 1000000007; // 10^9+7
const ll INF = 10000000000;

ll book[15][15];

int main(void){
    int n,m,x;
    cin >> n >> m >> x;

    rep(i,n){
        rep(j,m+1){
            cin >> book[i][j];
        }
    }

    ll money = INF;

    for(int bit = 0; bit < (1<<n); bit++){
        vector<ll> skill(m+1,0);
        for(int i = 0; i < n; i++){
            if(bit & (1<<i)){
                skill[0] += book[i][0];
                rep1(j,m) skill[j] += book[i][j];
            }
        }
        bool flag = true;
        rep1(k,m){
            if(skill[k] < x){
                flag = false;
                break;
            }
        }
        if(flag) money = min(money,skill[0]);
    }

    if(money == INF) cout << -1 << endl;
    else cout << money << endl;

    return 0;
}
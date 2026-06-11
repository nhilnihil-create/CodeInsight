#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000000007
#define MAX 2005

vector<vector<ll>> dp(MAX, vector<ll>(MAX, 0));
vector<vector<ll>> sm(MAX, vector<ll>(MAX, 0));

ll getVal(int i, int j){
    if( i >= 0 && j >= 0 )
        return sm[i][j];

    return 0;
}

void updateVal(int i, int j){
    int im = i-1, jm = j-1;
    ll vl = dp[i][j];
    if( im >= 0 )
        vl += sm[im][j];
    if( jm >= 0 )
        vl += sm[i][jm];
    if( im >= 0 && jm >= 0 )
        vl -= sm[im][jm];
    vl = vl%MOD;
    if( vl < 0 )
        vl += MOD;
    sm[i][j] = vl;
}

ll getTot(vector<vector<ll>> &dp, int x, int y){
    ll ans = 0;
    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
            ans += dp[i][j];

    return ans;
}

int main(){

    int n, m;
    cin >> n >> m;

    vector<int> an(n), am(m);

    for(int i = 0; i < n; i++)
        cin >> an[i];

    for(int i = 0; i < m; i++)
        cin >> am[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if( an[i] == am[j] ){
                dp[i][j] = (getVal(i-1, j-1) + 1)%MOD;
            }
            updateVal(i, j);
        }

    cout << (getVal(n-1, m-1)+1)%MOD << endl;
    return 0;
}
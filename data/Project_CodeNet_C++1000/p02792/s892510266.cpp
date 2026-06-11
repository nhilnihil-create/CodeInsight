#include <bits/stdc++.h>          
using namespace std;               
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    vector<vector<ll>> vec(9,vector<ll>(9,0));

    for (ll i=1; i<=N; i++) {
        ll keta = 1;
        ll i_temp = i;
        while (i_temp>=10) {
            i_temp/=10;
            keta++;
        }
        ll i_st = i/pow(10,keta-1);
        ll i_en = i%10;
        if (i_en!=0) {
            vec[i_st-1][i_en-1]++;
        }
    }
    ll ans = 0;
    for (ll i=0; i<9; i++) {
        for (ll j=0; j<9; j++) {
            ans += vec[i][j]*vec[j][i];
        }
    }
    cout << ans << endl;
}
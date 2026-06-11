#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;
#define rep(i, n)  for (int i = 0; i <  (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const ll INF = ll(1e18)+1;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> ai(n);
    rep(i,n) cin >> ai[i];

    ll money = 1000;
    ll stock = 0;

    vector<vector<ll>> bsvec(99,vector<ll>(2,0));
    ll mode = 0;

    bsvec[0][1] = ai[n-1];
    bsvec[0][0] = ai[n-1];

    rep(i,n-1){
        if(ai[n-2-i] <= bsvec[mode][0]) bsvec[mode][0] = ai[n-2-i];
        else{
            mode++;
            bsvec[mode][0] = ai[n-2-i];
            bsvec[mode][1] = ai[n-2-i];
        }
    }

    ll temp,temp2;
    rep(i,mode+1){
        if(bsvec[mode-i][0] != bsvec[mode-i][1]){
            money = money / bsvec[mode-i][0] * (bsvec[mode-i][1] - bsvec[mode-i][0]) + money;
        }
    }

    cout << money;
}
#include<bits/stdc++.h>
using namespace std;
#define rep(i, c) for(ll i = 0; i < (ll)c; i++)
#define ll long long
#define upd_max(maxer, updater) if (maxer < updater) maxer = updater;
#define upd_min(miner, updater) if (miner > updater) miner = updater;
const int inf = 1000000000; // 10^9

int main(){
    ll n, i = 0;

    bool ng = true;

    cin >> n;

    while(i <= n){
        if(i*108/100 == n){
            cout << i << endl;
            ng = false;
            break;
        }
        else i++;
    }

    if(ng) cout << ":(" << endl;

    return 0;
}
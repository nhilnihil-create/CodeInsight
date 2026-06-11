#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n;
    cin >> n;
    vector <vector <ll>> gs(n,vector <ll> (2));
    ll x,l;

    rep(i,n){
        cin >> x >> l;
        gs[i][0]=x+l;
        gs[i][1]=x-l;
    }

    sort(gs.begin(),gs.end());
    ll g;
    g=gs[n-1][0];
    ll s=gs[0][0];
    ll k=1;
    rep(i,n){
        if(gs[i][1]>=s){
            s=gs[i][0];
            ++k;
        }
    }
    cout << k << endl;
    

    return 0;
}
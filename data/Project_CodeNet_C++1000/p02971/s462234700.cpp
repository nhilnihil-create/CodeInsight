#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n), tmp(n);
    rep(i, n){
        cin >> a[i];
        tmp[i] = a[i];
    }

    bool flg = true;
    rep(i, n-1){
        if(a[i] != a[i+1]){
            flg = false;
            break;
        }
    }

    if(flg){
        rep(i, n) cout << a[0] << endl;
        return 0;
    }

    sort(tmp.begin(), tmp.end());
    ll amax = tmp[n-1], asec = tmp[n-2];

    rep(i, n){
        if(a[i] == amax) cout << asec << endl;
        else cout << amax << endl;
    }
    

    return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a.at(i);
    ll sum = 0;
    rep(i,n) sum += a.at(i);
    ll t = 0;
    for(int i = 1;i < n; i+=2){
        t += a.at(i);
    }
    ll x1 = sum / 2 - t;
    vector<ll> ans(n,0);
    ans.at(0) = x1;
    for(int i = 0; i < n -1;i++){
        ans.at(i+1) = a.at(i) - ans.at(i);
    }
    rep(i,n) cout << 2*ans.at(i) << " ";
    cout << endl;
}
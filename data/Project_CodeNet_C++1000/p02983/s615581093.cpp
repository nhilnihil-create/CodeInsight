#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    ll l,r;
    cin >> l >> r;
    vector<int> amari;
    int count = min(ll(2019),r - l+1);
    ll s = l;
    while(count--){
        amari.push_back(s%2019);
        s++;
    }
    int n = amari.size();
    int ans = 2018;
    for(int i = 0;i < n;i++){
        for(int j = i+1;j < n;j++){
            ans = min(ans,amari.at(i) * amari.at(j) % 2019);
        }
    }
    // rep(i,n) cout << amari.at(i) << endl;
    cout << ans << endl;
}
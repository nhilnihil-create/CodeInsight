#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
    int n,m;
    cin >> n >> m;
    multiset<ll> s;

    rep(i,n){
        ll temp;
        cin >> temp;
        s.insert(temp);
    }

    rep(i,m){
        ll temp = *s.rbegin();
        s.erase(--s.end());
        s.insert(temp/2);
    }

    ll ans = 0;
    for(auto v:s) ans += v;

    cout << ans << endl;


}
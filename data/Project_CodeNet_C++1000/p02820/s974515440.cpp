#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n,k,r,s,p;
    cin >> n >> k >> r >> s >> p;
    string t;
    cin >> t;
    vector<char> d(n);
    rep(i,n){
        if(t.at(i) == 'r') d.at(i) = 'p';
        if(t.at(i) == 's') d.at(i) = 'r';
        if(t.at(i) == 'p') d.at(i) = 's';
    }
    ll ans = 0;
    rep(i,n){
        if(i >= k && d.at(i-k) == d.at(i)) {
            d.at(i) = '#';
            continue;
        }
        if(d.at(i) == 'r') ans += r;
        if(d.at(i) == 's') ans += s;
        if(d.at(i) == 'p') ans += p;
    }
    cout << ans << endl;
}
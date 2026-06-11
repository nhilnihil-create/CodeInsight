#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const bool debug = false;

int main(){
    string s,t;
    cin >> s >> t;
    int n,m;
    n = s.size();
    m = t.size();
    vector<vector<int>> sidx(26), tidx(26);
    rep(i,n) {
        sidx.at(s.at(i) - 'a').push_back(i);
    }
    rep(i,m) {
        tidx.at(t.at(i) - 'a').push_back(i);
    }
    // rep(i,26){
    //     cout << (char)('a' + i) << " : ";
    //     for(int c : sidx.at(i)){
    //         cout << c << " ";
    //     }
    //     cout << endl;
    // }

    ll cur = -1;
    ll rc = 0;
    rep(i,m){
        int idx = t.at(i)-'a';
        if(sidx.at(idx).empty()){
            cur = -2;
            break;
        }
        ll l=-1;
        ll r = sidx.at(idx).size();
        while(l+1<r){
            ll md = (l+r)/2;
            if(sidx.at(idx).at(md) + rc*n > cur) r = md;
            else l = md;
        }
        if(debug) cout << "r:" << r << endl;

        if(r == sidx.at(idx).size()){
            rc++;
            cur = rc*n + sidx.at(idx).at(0);
        } else {
            cur = rc*n + sidx.at(idx).at(r);
        }
        if(debug) cout << cur << endl;
    }
    cout << cur+1 << endl;
    return 0;
}
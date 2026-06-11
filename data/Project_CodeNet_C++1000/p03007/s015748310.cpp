#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll n;
    cin >> n;
    VL a(n);
    rep(i, 0, n) cin >> a[i];
    VL pos, neg;
    rep(i, 0, n) {
        if(a[i] >= 0) pos.push_back(a[i]);
        else neg.push_back(a[i]); 
    }
    sort(ALL(pos),greater<ll>());
    sort(ALL(neg));
    if(neg.empty()) {
        neg.push_back(pos.back());
        pos.pop_back();
    }
    if(pos.empty()) {
        pos.push_back(neg.back());
        neg.pop_back();
    }
    VP res;
    ll cur = neg[0];
    rep(i, 0, pos.size()-1) {
        res.push_back({cur, pos[i]});
        cur -= pos[i];
    }
    res.push_back({pos.back(), cur});
    cur = pos.back() - cur;
    rep(i, 1, neg.size()) {
        res.push_back({cur, neg[i]});
        cur -= neg[i];
    }
    cout << cur << endl;
    for(auto e : res) cout << e.first << " " << e.second << endl;
    return 0;
}
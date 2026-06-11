#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

vector<pair<char,ll>> run_length_encoding(string s){
    vector<pair<char,ll>> res;
    ll n = s.size();
    char prev = -1;
    ll cur = 1;
    for(ll i = 0; i < n; i++) {
        if(prev == s[i]) cur++;
        else {
            if(prev != -1) res.push_back({prev, cur});
            prev = s[i];
            cur = 1;
        } 
    }
    res.push_back({prev, cur});
    return res;
}

int main(){
    string s;
    ll k;
    cin >> s >> k;
    ll n = s.size();
    auto v = run_length_encoding(s);
    if(v.size() == 1) {
        cout << k * v[0].second / 2 << endl;
        return 0;
    } 
    ll unit = 0;
    for(auto e : v) {
        unit += (e.second / 2);
    }
    auto head = (*v.begin()).second;
    auto tail = (*v.rbegin()).second;
    if((*v.begin()).first == (*v.rbegin()).first){
        cout << k * unit - (head / 2 + tail / 2 - (head + tail) / 2) * (k - 1) << endl;
    }else{
        cout << k * unit << endl;
    }
    return 0;
}
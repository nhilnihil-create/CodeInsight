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
    map<string, ll> mp;
    ll n;
    cin >> n;
    rep(i, 0, n){
        string s;
        cin >> s;
        mp[s]++;
    }
    ll mx = 0;
    vector<string> ans;
    for(auto e : mp){
        if(e.second > mx) {
            ans.clear();
            ans.push_back(e.first);
            mx = e.second;
        }else if(e.second == mx) {
            ans.push_back(e.first);
        }
    }
    sort(ALL(ans));
    for(auto e : ans) cout << e << endl;
    return 0;
}
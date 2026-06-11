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
    string S, T;
    cin >> S >> T;
    VVL rec(26);
    rep(i, 0, S.size()) rec[S[i]-'a'].push_back(i);
    ll pre = -1;
    ll ans = 0;
    rep(i, 0, T.size()){
        if(rec[T[i]-'a'].empty()){
            cout << -1 << endl;
            return 0;
        }
        auto itr = upper_bound(ALL(rec[T[i]-'a']), pre);
        if(itr == rec[T[i]-'a'].end()){
            pre = rec[T[i]-'a'][0];
            ans += S.size();
        }else{
            pre = *itr;
        }
    }
    ans += pre + 1;
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    string S,T;
    cin >> S >> T;
    map<char,vector<ll>> mp;
    int N = S.size();
    int M = T.size();
    rep(i,N){
        mp[S[i]].push_back(i);
    }
    rep(i,M){
        if(mp[T[i]].empty()){
            cout << -1 << endl;
            return 0;
        }
    }
    ll ans = 0;
    ll pos = 0;
    rep(i,M){
        char c = T[i];
        auto itr = lower_bound(mp[c].begin(),mp[c].end(),pos);
        if(itr == mp[c].end()){
            // Sの最後まで見てもCが見つからなかった場合は次のSへ
            ans += S.size() - pos;
            pos = 0; // 一度リセット
            ans += mp[c][0] + 1; // Cが出てくる最初の位置まで進む
            pos = mp[c][0] + 1;
        }else{
            ans += *itr - pos + 1;
            pos = *itr + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
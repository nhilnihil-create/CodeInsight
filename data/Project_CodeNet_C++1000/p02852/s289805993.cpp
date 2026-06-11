#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    ll i = N;
    vector<ll> ans;
    while(true){
        bool f = true;
        for(ll j = M; j >= 1; j--){
            if(i-j < 0) continue;
            if(S[i-j] == '0'){
                i = i-j;
                ans.push_back(j);
                f = false;
                break;
            }
        }
        if(f){
            cout << -1 << endl;
            return 0;
        }
        if(i == 0) break;
    }

    reverse(ans.begin(), ans.end());
    rep(i, 0, ans.size()) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
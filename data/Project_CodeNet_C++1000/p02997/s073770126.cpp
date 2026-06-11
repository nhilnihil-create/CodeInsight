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
    ll N, K;
    cin >> N >> K;
    if(K > (N-1) * (N-2) / 2){
        cout << -1 << endl;
        return 0;
    }

    VP ans;
    rep(i, 2, N+1){
        ans.push_back({1, i});
    }

    ll rem = (N - 1) * (N - 2) / 2 - K;
    ll cnt = 0;
    if(rem != 0){
        rep(i, 2, N){
            bool f = false;
            rep(j, i+1, N+1){
                ans.push_back({i, j});
                cnt++;
                if(cnt == rem){
                    f = true;
                    break;
                }
            }
            if(f) break;
        }
    }

    cout << ans.size() << endl;
    for(auto a : ans) cout << a.first << " " << a.second << endl; 
    return 0;
}
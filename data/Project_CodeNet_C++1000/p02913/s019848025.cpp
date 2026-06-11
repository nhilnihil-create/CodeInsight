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

vector<ll> Zalgo(string S){
    ll N = S.size();
    vector<ll> ret(N);
    ret[0] = N;
    ll i = 1, j = 0;
    while(i < N){
        while(i + j < N && S[j] == S[i+j]) j++;
        ret[i] = j;
        if(j == 0){
            i++;
            continue;
        }
        ll k = 1;
        while(i + k < N && k + ret[k] < j){
            ret[i+k] = ret[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return ret;
}

int main(){
    ll N;
    string S;
    cin >> N >> S;

    ll ans = 0;
    rep(i, 0, N){
        string T = S.substr(i);
        auto lcp = Zalgo(T);

        rep(j, 0, lcp.size()){
            ll l = min(lcp[j], j);
            ans = max(ans, l);
        }
    }

    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

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
    ll N; string S;
    cin >> N >> S;
    ll ans = 0;
    rep(i, 0, N){
        auto tmp = Zalgo(S.substr(i));
        rep(j, 1, tmp.size()){
            ans = max(ans, min(j, tmp[j]));
        }
    }
    cout << ans << endl;
    return 0;
}
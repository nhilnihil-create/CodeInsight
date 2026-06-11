#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N+1);
    rep(i, 1, N+1) cin >> A[i];
    vector<ll> acc(N+1, 0);
    rep(i, 1, N+1) acc[i] = acc[i-1] + A[i];  
    rep(i, 1, N+1) acc[i] = (acc[i] - i) % K;
    map<ll,ll> mp;
    ll ans = 0;
    rep(i, 0, N+1){
        ans += mp[acc[i]];
        mp[acc[i]]++;
        if(i - K + 1 >= 0) mp[acc[i-K+1]]--;
    }
    cout << ans << endl;
    return 0;
}
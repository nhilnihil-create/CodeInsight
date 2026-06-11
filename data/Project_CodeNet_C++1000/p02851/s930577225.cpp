#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ll N, K;  cin >> N >> K;
    vector<ll> A(N+1, 0);
    vector<ll> S(N+1, 0);
    for(int i=1; i<=N; i++){
        cin >> A[i];
        A[i]--;
        S[i] = (S[i-1] + A[i])%K;
    }

    map<ll, ll> mp;
    ll ans = 0;
    for(int i=0; i<=N; i++){
        if(i - K >= 0){
            mp[S[i-K]]--;
        }
        ans += mp[S[i]];
        mp[S[i]]++;
    }
    cout << ans << endl;
}
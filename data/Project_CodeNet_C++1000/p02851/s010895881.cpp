#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    ll N, K; cin >> N  >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }       

    vector<ll> S(N+1);
    S[0] = 0;
    for (int i = 1; i <= N; i++) {
        S[i] = (K + S[i-1] + A[i-1] - 1) % K;
    }

    map<ll,ll> mp;
    ll ans = 0;
    for (int i = 0; i <= N; i++) {
        ans += mp[S[i]];
        if(i >= K-1){
            mp[S[i-K+1]]--;
        }
        if(!mp.count(S[i])){
            mp[S[i]] = 0;
        }
        mp[S[i]]++;
    }
    printf("%lld\n", ans);



}

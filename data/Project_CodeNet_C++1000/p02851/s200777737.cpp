#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,K;
    cin >> N >> K;
    vec<ll> A(N),S(N+1);
    for(int i=0;i<N;i++){
        cin >> A[i];
        A[i]--;
        S[i+1] = (S[i]+A[i])%K;
    }
    map<ll,ll> mp;
    mp[0] = 1;
    ll ans = 0;
    for(int i=0;i<N;i++){
        if(i-K+1>=0) mp[S[i-K+1]]--;
        if(mp.count(S[i+1])) ans += mp[S[i+1]];
        mp[S[i+1]]++;
    }
    cout << ans << "\n";
}
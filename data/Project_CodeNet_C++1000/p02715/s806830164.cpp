#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

vector<ll> bitconversion(ll i, ll n, ll N){
    ll x = 1;
    rep(j,N){
        x *= n;
    }
    vector<ll> vec(N);
    rep(j,N){
        x /= n;
        vec[j] = i / x;
        i -= x * vec[j];
    }
    return vec;
}

ll iterative_square_method(ll i, vector<ll> &vec, ll N, ll mod){
    ll ans = 1;
    rep(j,N){
        if (vec[N - 1 - j] == 1) ans = (ans * i) % mod;
        i = (i * i) % mod;
    }
    return ans;
}

int main(){
    ll N,K;
    cin >> N >> K;
    ll ans = 0;
    vector<ll> vec_count(100002, 0);
    for (ll i = K; i >= 1; i--){
        ll cnt = K / i;
        vector<ll> binary = bitconversion(N, 2, 20);
        ll ans_sub = iterative_square_method(cnt, binary, 20, 1000000007);
        for (ll j = 2; j * i <= K; j++){
            ans_sub = (ans_sub + 1000000007 - vec_count[i * j]) % 1000000007;
        }
        vec_count[i] = ans_sub;
        ans = (ans + ans_sub * i) % 1000000007;
    }
    cout << ans << endl;
}
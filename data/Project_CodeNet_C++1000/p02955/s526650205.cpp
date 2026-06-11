#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

ll N, K;
ll A[510];

int main(){
    cin >> N >> K;
    ll sum = 0;
    for(ll i = 0; i < N; i++){
        cin >> A[i];
        sum += A[i];
    }
    vector<ll> div;
    for(ll j = 1; j * j <= sum; j++){
        if(sum % j == 0){
            div.push_back(j);
            div.push_back(sum / j);
        }
    }
    sort(div.begin(), div.end());
    ll ans = 1;
    for(auto u : div){
        vector<ll> d;
        ll g = 0;
        for(ll i = 0; i < N; i++){
            ll tmp = (((A[i] - 1) / u) + 1) * u - A[i];
            d.push_back(tmp);
            g += tmp;
        }
        sort(d.begin(), d.end());
        ll f = g / u;
        ll cnt = 0;
        for(ll i = 0; i < N - f; i++){
            cnt += d[i];
        }
        if(cnt <= K) ans = u;
    }
    cout << ans << endl;
    return 0;
}
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

int main(){
    ll N;
    cin >> N;
    vector<ll> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    vector<vector<ll> > bit60(N, vector<ll>(60));
    rep(i,N){
        vector<ll> binary = bitconversion(vec[i], 2, 60);
        rep(j,60){
            bit60[i][j] = binary[j];
        }
    }
    ll ans = 0;
    ll num = 1;
    for (int i = 59; i >= 0; i--){
        ll count_0 = 0;
        rep(j,N){
            if (bit60[j][i] == 0) count_0++;
        }
        ans += ((num % 1000000007) * (((N - count_0)* count_0) % 1000000007)) % 1000000007;
        num *= 2;
        ans = ans % 1000000007;
    }
    cout << ans << endl;
}

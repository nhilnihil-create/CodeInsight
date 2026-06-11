#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    string S;
    cin >> N >> S;
    vector<ll> vec(2 * N);
    vec[0] = 0;
    rep(i,2 * N - 1){
        if (S[i + 1] == S[i]){
            if (vec[i] == 0) vec[i + 1] = 1;
            if (vec[i] == 1) vec[i + 1] = 0;
        }
        else{
            vec[i + 1] = vec[i];
        }
    }
    vector<ll> left(2 * N, 0);
    vector<ll> right(2 * N, 0);
    ll ans = 1;
    left[0] = 1;
    rep(i,2 * N - 1){
        if (vec[i + 1] == 0) left[i + 1]++;
        if (vec[i + 1] == 1) right[i + 1]++;
        left[i + 1] += left[i];
        right[i + 1] += right[i];
    }
    vector<ll> fact(100005);
    fact[0] = 1;
    for (ll i = 1; i < 100005; i++){
        fact[i] = (fact[i - 1] * i) % 1000000007;
    }
    rep(i,2 * N - 1){
        if (vec[i + 1] == 1){
            ans = (ans * (left[i] - right[i])) % 1000000007;
        }
    }
    bool possible = true;
    if (S[0] == 'W') possible = false;
    if (left[2 * N - 1] !=  right[2 * N - 1]) possible = false;
    
    if (!possible) cout << 0 << endl;
    else{
        cout << (ans * fact[N]) % 1000000007 << endl;
    }
    
}

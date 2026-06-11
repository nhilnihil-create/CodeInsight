#include<bits/stdc++.h> 
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y){
    if (y == 0) return x;
    return gcd(y, x % y);
}

struct Eratos{
    vector<int> first_prime; //その数を割り切る最小の素数,その数自身のとき素数とわかる
    vector<int> P;

    Eratos(int N){
        first_prime.resize(N + 1);
        rep (i, N + 1)
            first_prime[i] = i;
        for(int i = 2; i <= N; i++){
            if(first_prime[i] == i){
                for(int j = 2 * i; j <= N; j += i){
                    first_prime[j] = min(first_prime[j], i);
                }
                P.pb(i);
            }
        }
    }
    vector<int> factorization(int n, vector<int> &f){
        if (n == 1)
            return f;
        else {
            f.pb(first_prime[n]);
            return factorization(n / first_prime[n], f);
        }
    }
};

int main(){
    ll a, b;
    cin >> a >> b;
    ll g = gcd(a, b);
    Eratos er(1e6);
    ll ans = 1;
    rep(i, er.P.size()){
        if (g % er.P[i] == 0){
            while (g % er.P[i] == 0)
                g /= er.P[i];
            ans ++;
        }
    }
    if (g != 1) ans++;
    cout << ans << endl;
}
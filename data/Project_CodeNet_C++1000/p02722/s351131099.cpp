#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> divisors(0);
    for (ll i = 2; i * i <= N; i++){
        if (N % i == 0){
            divisors.push_back(i);
            if (i != N / i) divisors.push_back(N / i);
        }
    }
    divisors.push_back(N);
    ll ans = 0;
    ll len = divisors.size();
    rep(i,len){
        ll N_copy = N;
        while(true){
            if (N_copy % divisors[i] != 0) break;
            else N_copy /= divisors[i];
        }
        if ((N_copy - 1) % divisors[i] == 0) ans++;
    }
    vector<ll> divisors2(0);
    for (ll i = 2; i * i <= N - 1; i++){
        if ((N - 1) % i == 0){
            divisors2.push_back(i);
            if (i != (N - 1) / i) divisors2.push_back((N - 1) / i);
        }
    }
    divisors2.push_back(N - 1);
    ll len2 = divisors2.size();
    ans += len2;
    if (N == 2) cout << 1 << endl;
    else cout << ans << endl;
}
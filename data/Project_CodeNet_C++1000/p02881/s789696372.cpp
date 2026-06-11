#include <bits/stdc++.h>          
using namespace std;
typedef long long ll;

vector<ll> prime;//素因数分解で出てきた素数を全て挿入するvector

//O(√n)
//整列済み
/*
void prime_factorize(ll n){
    if(n<=1) return;
    ll l=sqrt(n);
    for(ll i=2; i<=l; i++){
        if(n%i==0){
        prime_factorize(i);
        prime_factorize(ll(n/i));
        return;
        }
    }
    prime.push_back(n);
    return;
}
*/
int main() {
    ll N;
    cin >> N;
    vector<ll> cnt;
    for (ll i=1; i*i<=N; i++) {
        if (N%i==0) {
            cnt.push_back(i+N/i-2);
        }
    }
    sort(cnt.begin(),cnt.end());
    cout << cnt[0] << endl;
    /*
    prime_factorize(N);
    ll n = prime.size();
    vector<ll> vec(n);
    vec[0] = prime[0];
    for (ll i=1; i<n; i++) {
        if (prime[i-1]==prime[i]) {
            vec[i]=vec[i-1]*prime[i];
        }
        else {
            vec[i]=prime[i];
        }
    }
    vector<ll> cnt(n);
    for (ll i=0; i<n; i++) {
        cnt[i] = vec[i] + N/vec[i] - 2;
    }
    sort(cnt.begin(),cnt.end());
    cout << cnt[0] << endl;
    */
}
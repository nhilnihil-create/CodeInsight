#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#define all(a) (a).begin(),(a).end()
#define vecin(a) rep(i,a.size())cin >> a[i]
#define vecout(a) rep(i,a.size()){cout << a[i];cout << (i == a.size() - 1 ? "\n":" ");}
#define mp make_pair
using ll = long long;
using ld = long double;
using namespace std;
using dou = double;
const ll inf = 2147483647;
const ll INF = 1LL << 60;
const dou pi = 3.14159265358;
const ll mod = 1000000007LL;
//const ll mod = 998244353LL;
typedef pair<ll,ll> P;
using graph = vector<vector<ll>>;
template<class T> inline bool chmax(T& a, T b){if(a < b){a = b; return true;}return false;}
template<class T> inline bool chmin(T& a, T b){if(a > b){a = b; return true;}return false;}
template<class T> inline bool change(T a,T b){if(a > b){swap(a,b);return true;}return false;}
ll gcd(ll a,ll b){
    if(a < b)swap(a,b);
    if(a % b == 0)return b;
    else return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a / gcd(a,b) * b;
}

//素数判定O(sqrt(N))
bool isp(ll n){
    bool res = true;
    if(n == 1)return false;
    else{
        for(ll i = 2;i * i <= n;i++){
            if(n % i == 0){
                res = false;
                break;
            }
        }
        return res;
    }
}
const ll cmax = 1000000;
ll fac[cmax], finv[cmax], inv[cmax];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < cmax; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

// 二項係数計算
ll nCk(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
//nのm乗をMODで割ったあまりO(logm)
ll modpow(ll n,ll m,ll MOD){
    if(m == 0)return 1;
    if(m < 0)return -1;
    ll res = 1;
    while(m){
        if(m & 1)res = (res * n) % MOD;
        m >>= 1;
        n *= n;
        n %= MOD;
    }
    return res;
}
ll mypow(ll n,ll m){
    if(m == 0)return 1;
    if(m < 0)return -1;
    ll res = 1;
    while(m){
        if(m & 1)res = (res * n);
        m >>= 1;
        n *= n;
    }
    return res;
}
//printf("%.10f\n", N);
/*  vector<ll> vec = {1,2,5,6,8,9,10};
    cout << binary_search(all(vec),5) << endl; -> true*/
/*
    vector<ll> vec = {1,2,5,6,8,9,10};
    auto n = upper_bound(all(vec),4);
    cout << *n << endl; -> 5*/

//    cout << fixed << setprecision(15);

#define rep(i,x) for(ll i = 0;i<x;i++)
#define REP(i,x) for(ll i = 1;i<=x;i++)
ll popcount(ll n){
    ll res = 0;
    while(n){
        if(n&1)res++;
        n/=2;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll ans = 0;
    rep(i,1000){
        bool one = false,two = false,thr = false;
        string T = to_string(i);
        if(i < 100 && i >= 10)T = '0' + T;
        else if(i < 10)T = "00" + T;
        rep(j,N){
            if(!one && T[0] == S[j]){
                one = 1;
            }
            else if(!two && one && T[1] == S[j]){
                two = 1;
            }
            else if(!thr && two && T[2] == S[j]){
                thr = 1;
                break;
            }
        }
        if(one && two && thr)ans++;
    }
    cout << ans << endl;
}
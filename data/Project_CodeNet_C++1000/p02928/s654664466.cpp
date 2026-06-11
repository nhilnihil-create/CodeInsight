#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (int i = m; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using PL = pair<long long, long long>;
const int INF = 1001001007;
const int mod = 1000000007;

int main(){
    ll n, m; cin >> n >> m;
    vector<int> ar(n);
    rep(i,n) cin >> ar[i];
    vector<int> le(n);
    vector<int> ri(n);
    repl(i,n){
        int a = 0;
        repl(j,i){
            if (ar[j] > ar[i]) a++;
        }
        int b = 0;
        reppl(j,n,i+1){
            if (ar[j] > ar[i]) b++;
        }
        le[i] = a; ri[i] = b;
    }
    ll sle = 0; ll sri = 0;
    rep(i,n){
        sle += le[i];
        sri += ri[i];
    }
    ll ale = (m * (m+1) / 2 % mod) * sle % mod;
    ll ari = (m * (m-1) / 2 % mod) * sri % mod;
    cout << (ale + ari) % mod << endl;
}
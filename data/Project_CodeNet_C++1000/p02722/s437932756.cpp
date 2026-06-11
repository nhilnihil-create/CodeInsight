#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (long long i = m; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Pxy = pair<long double, long double>;
using T = tuple<int, int, bool>;
const int INF = 1001001007;
const int MOD = 1000000007;
const ll inf = 1e18;
template <typename AT>
void printvec(vector<AT> &ar){
    rep(i,ar.size()-1) cout << ar[i] << " ";
    cout << ar[ar.size()-1] << endl;
}
template <typename Q>
void printvvec(vector<vector<Q>> &ar){
    rep(i,ar.size()){
        rep(j,ar[0].size()-1) cout << ar[i][j] << " ";
        cout << ar[i][ar[0].size()-1] << endl;
    }
}
template <typename S>
bool range(S a, S b, S x){
    return (a <= x && x < b);
}

int main() {
    ll k; cin >> k;
    ll x = k;
    k--;
    ll n = sqrt(k);
    int ans = 0;
    vector<int> ar(n+1,0);
    while (k % 2 == 0){
        ar[2]++;
        k /= 2;
    }
    for (int i = 3; i < n+1; i += 2){
        while (k % i == 0){
            ar[i]++;
            k /= i;
        }
        if (k == 1) break;
    }
    int cnt = 1;
    rep(i,n+1){
        cnt *= ar[i]+1;
        //rep(j,ar[i]) cout << i << endl;
    }
    if (k != 1) cnt *= 2;
    ans += cnt-1;
    n = sqrt(x);
    repp(i,n+1,2){
        ll y = x;
        while (y % i == 0){
            y /= i;
        }
        if (y < x && y % i == 1) ans++;
    }
    ans++;
    cout << ans << endl;
}
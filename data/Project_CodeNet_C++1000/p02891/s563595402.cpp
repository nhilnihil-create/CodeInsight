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
using Pxy = pair<double, double>;
using T = tuple<int, int, bool>;
const int INF = 1001001007;
const int MOD = 1000000007;
//const int MOD = 998244353;
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
    string s; cin >> s;
    int n = s.size();
    ll k; cin >> k;
    ll ans = 0;
    ll cnt = 0;
    bool t = true;
    rep(i,n){
        if (s[0] != s[i]){
            t = false;
            break;
        }
    }
    if (t){
        cout << n * k / 2 << endl;
        return 0;
    }
    char le = s[0];
    char ri = s[n-1];
    if (le == ri){
        int l = 0; int r = 0;
        rep(i,n){
            if (s[i] == le) l++;
            else break;
        }
        rep(i,n){
            if (s[n-1-i] == ri) r++;
            else break;
        }
        char c = '!';
        repp(i,n-r,l){
            if (s[i] != c) c = s[i];
            else {
                c = '!';
                cnt++;
            }
        }
        ans = cnt * k;
        ans += l / 2;
        ans += r / 2;
        ans += (r + l) / 2 * (k-1);
    }
    else {
        char c = '!';
        rep(i,n){
            if (s[i] != c) c = s[i];
            else {
                c = '!';
                cnt++;
            }
        }
        ans = cnt * k;
    }
    cout << ans << endl;
}
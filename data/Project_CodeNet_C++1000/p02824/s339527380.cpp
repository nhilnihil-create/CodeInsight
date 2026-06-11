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

bool che(vector<ll> ar, int k, ll n, ll m, ll v, ll p){
    if (k <= p-1) return true;
    if (ar[k]+m <ar[p-1]) return false;
    ll hyo = 0;
    hyo += (p-1) * m + (n - k) * m;
    reppl(i,k,p-1){
        hyo += min(ar[k]+m-ar[i],m);
    }
    if (hyo < m * v) return false;
    else return true;
}

int main() {
    ll n, m, v, p; cin >> n >> m >> v >> p;
    vector<ll> ar(n);
    repl(i,n) cin >> ar[i];
    sort(ar.rbegin(),ar.rend());
    //printvec(ar);
    int le = 0;
    int ri = n;
    int mid = (le + ri) / 2;
    while (ri - le > 1){
        if (che(ar,mid,n,m,v,p)){
            //cout << mid << " yes" << endl;
            le = mid;
        }
        else {
            //cout << mid << " no" << endl;
            ri = mid;
        }
        mid =(le + ri) / 2;
    }
    cout << le+1 << endl;
}
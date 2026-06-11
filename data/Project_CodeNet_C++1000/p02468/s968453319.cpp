#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
const long long INF = 1001001001;
const long long MOD = 1000000007;
const double EPS = 1e-10;
struct Edge { int from, to; long long cost; };
using Graph = vector<vector<Edge>>;

template<typename T = long long>
T mod_pow(T a, T x, T md) {
    T res = 1;
    while(x) {
        if(x & 1) res = res * a % md;
        a = a * a % md;
        x >>= 1;
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll m,n;
    cin>>m>>n;
    cout<<mod_pow(m,n,MOD)<<endl;
}

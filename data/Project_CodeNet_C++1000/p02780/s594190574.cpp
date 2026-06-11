#include <bits/stdc++.h>
// #include "../utils.h"

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef unsigned long long ll;

int main(){
    // read in integers
    ll n, k;
    cin >> n >> k;
    vector<long double> p(n, 0);
    REP(i, n) cin >> p[i];

    vector<long double> cs(n, 0);
    cs[0] = (long double)(1.0+p[0])/2.0;

    FOR(i, 1, n){
        cs[i] += cs[i-1] + (long double)(1.0+p[i])/2.0;
    }

    long double max = cs[k-1];
    FOR(i, k, n){
        if (cs[i]-cs[i-k] > max) max = cs[i]-cs[i-k];
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(12);
    cout << max << endl;

}
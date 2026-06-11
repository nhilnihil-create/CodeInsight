#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>

typedef unsigned long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;

int main(){
    ll m;
    cin >> m;
    vector<ll> c(m),d(m);
    for(int i = 0; i < m; i++){
        cin >> d[i] >> c[i];
    }

    ll sumc = 0, sumd = 0;
    for(int i = 0; i < m; i++){
        sumc += c[i];
        sumd += d[i]*c[i];
    }
    ll ans = sumc-1L + (sumd-1)/9L;
    cout << ans << endl;
    return 0;
}
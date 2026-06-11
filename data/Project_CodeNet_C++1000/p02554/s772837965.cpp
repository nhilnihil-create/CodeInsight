#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <math.h>
#include <queue>
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;

const ll INF=1000000007;

ll pmod(ll x,ll y) {
    ll res=1;
    rep(i,y) res=res*x%INF;
    return res;
}

int main() {
    ll n;
    cin >> n;
    ll ans = pmod(10,n)-pmod(9,n)-pmod(9,n)+pmod(8,n);
    ans%=INF;
    ans=(ans+INF)%INF;
    cout << ans << endl;
}   
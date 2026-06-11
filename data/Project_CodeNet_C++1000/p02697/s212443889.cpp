#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll N, M;
    cin >> N >> M;

    ll olt, ort, elt, ert, olen, elen;
    olen = M;
    elen = M-1;
    if(olen % 2 == 0) swap(olen, elen);

    olt = 1;
    ort = olt + olen;
    elt = ort + 1;
    ert = elt + elen;

    while(olt < ort) {
        cout << olt << " " << ort << endl;
        olt++, ort--;
    }
    while(elt < ert) {
        cout << elt << " " << ert << endl;
        elt++, ert--;
    }
}

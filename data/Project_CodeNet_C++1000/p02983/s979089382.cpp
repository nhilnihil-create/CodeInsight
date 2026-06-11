#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(long long i=0;i<(long long)(n);i++)
#define rep2(i, s, n) for(long long i=(s);i<(long long)(n);i++)
#define repi(i, n) for(int i=0;i<(int)(n);i++)
#define rep2i(i, s, n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(), v.end()

using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;

const ll INF = (1LL<<60);
const int INFi = (1<<29);

int main(){

    ll l, r; cin >> l >> r;

    ll ii, jj, ans = INF;
    for(ll i=l, ii=0;(i<=r-1)&&(ii<2019);i++, ii++){
        for(ll j=i+1, jj=0;(j<=r)&&(jj<2019);j++,  jj++){
            ans = min(ans, (i*j)%2019);
        }
    }

    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define m0(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); i++)
#define asort(x) sort(all(x));
#define dsort(x, t) sort(x.begin(), x.end(), greater<t>());
#define dump(x)  cout << #x << " = " << (x) << endl
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define MINS(m, s) m.insert(make_pair(s, 1));
#define MFIN(m, s) m.find(s) != m.end()
#define YES(n) cout << ((n) ? "YES" : "NO" ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No" ) << endl

const int INF = 1e9;
const ll LINF = 1e18;
const int mod = 1e9+7;

int main(){
    ll n;
    ll h[100005];
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> h[i];
    }
    ll maxCnt = 0;
    ll cnt = 0;
    for (ll i = 0; i < n-1; i++) {
        if(h[i] >= h[i+1]){
            cnt++;
        }else{
            cnt = 0;
        }
        maxCnt = max(maxCnt, cnt);
    }
    cout << maxCnt << endl;
    return 0;
}
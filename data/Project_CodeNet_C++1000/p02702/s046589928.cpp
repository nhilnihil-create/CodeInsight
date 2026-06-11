#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e9;
const ll MOD = 1e9 + 7;


int main(){
    string s;
    cin >> s;
    reverse(all(s));

    ll ans = 0;
    vector<ll> v(2019);
    v[0] = 1;//余りが0のものは1個で用を足すので、見つけたらすぐansに足せるように1を入れておく.
    ll d = 1, now = 0;
    rep(i, s.size()){
        now = (now + (s[i] - '0') * d) % 2019;
        ans += v[now];//順次足せば、総和の公式で集計しなくても良い(同じ事).
        v[now]++;
        d = (d*10) % 2019;
    }

    cout << ans << endl;
}
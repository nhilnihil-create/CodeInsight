#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<pair<ll, int>> factorize(ll n){
    vector<pair<ll, int>> res;
    for (ll i = 2; i*i <= n; ++i){
        if (n%i) continue;
        res.emplace_back(i, 0);
        while (n%i == 0){
            n /= i;
            res.back().second++;
        }
    }
    if(n != 1) res.emplace_back(n, 1);
    return res;
}

int main(){
    ll a, b;
    cin >> a >> b;
    ll g = __gcd(a, b);
    auto f = factorize(g);
    cout << f.size()+1 << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll inf = 1e18;

// retun n の約数の集合
vector<ll> divisors(ll n){
      vector<ll> y;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0) y.push_back(i);
    }
      ll len = y.size();
      REP(i, len){
        if(y[i] == n / y[i]) continue;
        y.push_back(n / y[i]);
    }
    return y;
}

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll res = 1, sq = sqrt(n);

    // N % K == 1
    for (auto y : divisors(n - 1)) {
        if (y > sq) res++;
    }

    REP(x, sq + 1) {
        if (x < 2) continue;
        ll mem = n;
        while (mem % x == 0) mem /= x;
        if (mem % x == 1) res++;
    }

    cout << res << endl;
    return 0;
}
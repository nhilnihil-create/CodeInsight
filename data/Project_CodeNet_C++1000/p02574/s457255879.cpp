#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define MOD 1000000007LL

#define rep(i, n) for(ll (i) = 0LL;(i) < (ll)(n);(i)++)
#define rep2(i, s, e) for(ll (i) = (ll)(s);(i) < (ll)(e);(i)++)
#define repi(i, n) for(ll (i) = 0LL;(i) <= (ll)(n);(i)++)
#define repi2(i, s, e) for(ll (i) = (ll)(s);(i) <= (ll)(e);(i)++)
#define per(i, n) for(ll (i) = (ll)(n) - 1LL;(i) >= 0LL;(i)--)
#define per2(i, s, e) for(ll (i) = (ll)(s) - 1LL;(i) >= (ll)(e);(i)--)
#define peri(i, n) for(ll (i) = (ll)(n);(i) >= 0LL;(i)--)
#define peri2(i, s, e) for(ll (i) = (ll)(s);(i) >= (ll)(e);(i)--)
#define iter(i, it) for(auto &(i): (it))

template<typename T, typename U> ostream& operator<<(ostream &s, const pair<T, U> m) {
    cout << "(" << m.first << ", " << m.second << ")";
    return s;
}
template<typename T, typename U> ostream& operator<<(ostream &s, const map<T, U> m) {
    ll c = 0;
    cout << "{ ";
    iter(i, m) cout << i << (c++ == m.size() - 1 ? " " : ", ");
    cout << "}";
    return s;
}
template<typename T> ostream& operator<<(ostream &s, const vector<T> &v) {
    cout << "{ ";
    rep(i, v.size()) cout << v[i] << (i == v.size() - 1 ? " " : ", ");
    cout << "}";
    return s;
}
template<typename T> ostream& operator<<(ostream &s, const list<T> &v) {
    ll c = 0;
    cout << "{ ";
    iter(i, v) cout << i << (c++ == v.size() - 1 ? " " : ", ");
    cout << "}";
    return s;
}

#define MAX 10000001
vector<ll> hurui(MAX);

void prepare() {
    hurui[1] = 1;
    rep2(i, 2, MAX) {
        if(hurui[i] == 0) {
            for(ll j = i;j < MAX;j += i) hurui[j] = i;
        }
    }
}

void factor(ll n, set<ll> &factors) {
    factors.insert(1);
    if(n == 1) return;
    while(true) {
        ll temp = hurui[n];
        factors.insert(temp);
        if(temp == n) break;
        n = n / temp;
    }
}

int main(void) {
    prepare();
    ll N;
    cin >> N;
    vector<ll> Araw(N);
    map<ll, ll> factors;
    rep(i, N) {
        set<ll> factorss;
        cin >> Araw[i];
        factor(Araw[i], factorss);
        iter(j, factorss) {
            if(j != 1) factors[j]++;
        }
    }
    bool flag = true;
    iter(i, factors) {
        if(i.second != 1) flag = false;
    }
    if(flag) {
        cout << "pairwise coprime";
    } else {
        ll gcd = Araw.front();
        rep2(i, 1, N) gcd = __gcd(gcd, Araw[i]);
        if(gcd == 1) cout << "setwise coprime";
        else cout << "not coprime";
    }
    cout << endl;
    return 0;
}

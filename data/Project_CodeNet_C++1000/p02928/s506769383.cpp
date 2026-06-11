// Template //
#include<bits/stdc++.h>
using namespace std;

// マクロ //
#define rep(i,N) for(int i = 0; i < N; i++)
#define all(x) x.begin(), x.end()
#define sort(x) sort(all(x))
#define uniq(x) x.erase(unique(all(x)), x.end())
#define vsum(x) accumulate(all(x), 0)
#define cou(x) cout << x << endl
#define y() cout << "Yes" << endl
#define n() cout << "No" << endl
#define Y() cout << "YES" << endl
#define N() cout << "NO" << endl
#define x2(x) (x) * (x)
#define db(i) cout << #i << " = " << i;

// 型エイリアス //
using lint = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vli = vector<lint>;
using vc = vector<char>;
using vs = vector<string>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vvb = vector<vb>;
using vvc = vector<vc>;
using vpii = vector<pii>;
using msi = map<string, int>;

// 関数 //
template<class T> lint gcd(T a, T b) {
    int t;
    while (b != 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

template<class T> lint lcm(T a, T b) {
    return a * b / gcd(a, b);
}

double distance(pii a, pii b) {
    double dist;
    dist = sqrt(x2(a.first - b.first) + x2(a.second - b.second));
    return dist;
}

lint perm(int a) {
    lint perm = 1;
    for (int i = a; i >= 1; i--) {
        perm *= i;
    }
    return perm;
}

lint combination(int n, int m) {
    long double c = 1;
    for (int i = n, k = 1; i > m; i--, k++) {
        c *= i;
        c /= k;
    }
    return (lint)c;
}

template<class T, class Q> inline bool chmin(T& a, Q b) {
    if (a > b) { 
        a = b;
        return true; 
    }
    return false;
}

template<class T, class Q> inline bool chmax(T& a, Q b) {
    if (a < b) { 
        a = b; 
        return true; 
    }
    return false;
}

// 定数 //
const double pi = acos(-1);
const int mod = 1000000007;
const int MOD = 998244353;
const int inf = 1045141919;
const lint linf = ((1LL << 62) - 1);


// キーワード //
#define elif else if

// End of Template //

void operator*(vli& vec, lint k) {
    rep(i, (int)vec.size()) {
        vec[i] = ((vec[i] % mod) * (k % mod)) % mod;
    }
    return;
}


int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
        
    int N, K;
    cin >> N >> K;
    vli A(N);
    map<lint, lint> appear;
    
    rep(i, N) {
        lint k;
        cin >> k;
        A[i] = k;
        if (appear.count(k)) {
            appear[k]++;
        }
        else {
            appear[k] = 1;
        }
    }
    vli aftsmal(N, 0);
    rep(i, N - 1) {
        for (int j = i + 1; j < N; j++) {
            if (A[i] > A[j]) {
                aftsmal[i]++;
            }
        }
    }
    vli smaller(N, 0);
    rep(i, N) {
        for (auto x : appear) {
            if (x.first == A[i]) break;
            smaller[i] += x.second;
        }
    }

    smaller * (K * (K - 1LL) / 2LL);
    aftsmal * K;
    
    lint tori = 0;
    rep(i, N) {
        tori = (tori + smaller[i]) % mod;
        tori = (tori + aftsmal[i]) % mod;
    }

    cou(tori);
}
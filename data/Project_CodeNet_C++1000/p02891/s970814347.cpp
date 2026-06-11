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


int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    string S, sub;
    lint N;
    cin >> S >> N;
    if (S.size() == 1) {
        cou(N / 2); exit(0);
    }
    sub = S;
    lint cnt = 0;
    rep(i, S.size() - 1) {
        if (sub[i] == sub[i + 1]) {
            sub[i + 1] = 'A';
            cnt++;
        }
    }
    lint beginconseq = 1;
    lint endconseq = 1;
    if (S[0] == S[S.size() - 1]) {

        int k = 0;
        while (S[k] == S[k + 1]) {
            k++;
            beginconseq++;
            if (beginconseq == S.size()) {
                cou(S.size() * N / 2); exit(0);
            }
        }
        int l = S.size() - 1;
        while (S[l] == S[l - 1]) {
            l--;
            endconseq++;
        }
        lint cnt_beg = cnt - beginconseq / 2;
        lint cnt_end = cnt - endconseq / 2;
        lint cnt_beg_end = cnt - beginconseq / 2 - endconseq / 2;
        lint beg_end = (beginconseq + endconseq) / 2;
        cou(cnt_end + cnt_beg + (N - 2) * cnt_beg_end + (N - 1) * beg_end);
    }
    else cou(cnt * N);
}
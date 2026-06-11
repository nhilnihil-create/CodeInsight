#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define vi vector<int>
#define vl vector<long long>
#define vvi vector< vector<int> >
#define vvl vector< vector<ll> >
#define vp vector<P>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPD(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define FORD(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define INF 1e18
#define INFTY 1e9
const int mod = 998244353;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

template<class T> bool chmax(T &a, const T & b) {
    if (a<b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> bool chmin(T &a, const T & b) {
    if (a>b) {
        a = b;
        return true;
    }
    return false;
}

//cout << fixed << setprecision(10) << y << endl;
struct edge {int to, cost;};
vector< vector<edge> > es;
const int MAX_N = 10010;

int gcd(int a, int b) {
    if (b > a) {
        int c = b;
        b = a;
        a = c;
    }
    int r = a % b;
    if (r == 0) return b;
    return gcd(b, r);
}

ll lcm(ll a, ll b) {
    return a/gcd(a, b)*b;
}

int main() {
    int n, m;
    cin >> n >> m;
    vl a(n);
    REP(i, n) cin >> a[i];
    int res = 0;
    ll l = 1;
    bool flag = true;
    int b = a[0];
    int cnt = 0;
    while (b % 2 == 0) {
        b /= 2;
        cnt += 1;
    }
    REP(i, n) {
        int c = 0;
        int num = a[i];
        while (num % 2 == 0) {
            num /= 2;
            c += 1;
        }
        if (cnt != c) {
            flag = false;
            break;
        }
    }
    REP(i, n) {
        a[i] /= 2;
        l = lcm(l, a[i]);
        if (l > m) {
            flag = false;
            break;
        }
    }

    if (flag) {
        res = (m/l+1)/2;
        cout << res << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}
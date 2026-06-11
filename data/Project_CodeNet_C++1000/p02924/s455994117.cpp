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

int main() {
    ll n;
    cin >> n;
    ll res = n*(n-1)/2;
    cout << res << endl;
    return 0;
}
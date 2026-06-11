#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()


int main() {
    ll s;
    cin >> s;
    if (s == 1e18) {
        printf("%d %d %d %d %d %d", int(1e9), int(1e9), 0, 0, int(1e9), 0);
        exit(0);
    }
    ll p = s / 1e9;
    ll q = s % int(1e9);
    printf("%d %d %d %d %d %d", int(1e9), 0, q, p+1, 0, 1);
}

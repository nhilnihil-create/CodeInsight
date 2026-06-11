#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;



template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;

ll gcd(ll n, ll m) {  // 最大公約数を求めるプログラム
    // nとmの最大公約数を返す関数
    if(m > n) {
        ll c = n;
        n = m; 
        m = c;
    }
    if(n%m == 0) return m;
    else return gcd(m, n%m);
}

ll lcm(ll n, ll m) {  // 最小公倍数を求めるプログラム
    // 依存:gcd
    return n * m / gcd(n, m);
}


int main(){
    int N, M;
    cin >> N >> M;
    int l;
    cin >> l;
    int X = l/2;
    rp(i, 1, N) {
        int a; cin >> a;
        int b = a/2;
        while(X < b) X += l;
        int flag = 1;
        while(flag) {
            if((X-b) % a == 0) {
                flag = 0; continue;
            }
            if(X > M) {
                printf("0\n");
                return 0;
            }
            X += l;
        }
        l = lcm(l, a);
    }
    if(X > M) {
        printf("0\n");
        return 0;
    }
    cout << int((M-X) / l) + 1 << endl;
    return 0;
}
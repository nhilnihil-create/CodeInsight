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


int main() {
    int N;
    cin >> N;
    vector<int> A;
    vector<ll> count(N+10);
    rp(i, 0, N) {
        int a;
        cin >> a;
        count[a]++;
        A.emplace_back(a);
    }
    ll res = 0ll;
    rp(i, 0, N+1) {
        if(count[i] != 0) res += count[i] * (count[i] - 1ll) / 2ll;
    }
    for(auto x: A) {
        printf("%lld\n", res - count[x] + 1);
    }
    return 0;

}
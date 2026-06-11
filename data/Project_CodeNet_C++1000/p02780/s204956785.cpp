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
    int N, K;
    cin >> N >> K;
    vector<ld> p;
    rp(i, 0, N) {
        ld pi;
        scanf("%lf", &pi);
        p.emplace_back((pi+1.0) / 2.0);
    }
    ld sum = 0;
    ld res = 0;
    rp(i, 0, K) {
        sum += p.at(i);
    }
    res = sum;
    for(int i = 0; i + K < N; i++){
        sum -= p.at(i);
        sum += p.at(i+K);
        chmax(res, sum);
    }
    printf("%.10lf\n", res);
    return 0;
}
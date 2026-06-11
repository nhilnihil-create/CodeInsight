#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    ll ans = 0;
    map<ll, ll> dist, sum;
    for (int i = 0; i < N; i++) {
        ll d = i - A.at(i);
        ll s = i + A.at(i);
        if (dist.count(d)) {
            dist.at(d)++;
        }
        else {
            dist[d] = 1;
        }
        if (sum.count(s)) {
            sum.at(s)++;
        }
        else {
            sum[s] = 1;
        }
    }
    for (int i = 0; i < N; i++) {
        if (dist.count(i) && sum.count(i)) {
            ans += dist.at(i) * sum.at(i);
        }
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N, M; cin >> N >> M;
    priority_queue<ll> pq;
    ll sum = 0;
    for(int i = 0; i < N; i++) {
        ll A; cin >> A;
        pq.push(A);
        sum += A;
    }
    while(M > 0 ) {
        ll n = pq.top(); pq.pop();
        sum -= (n + 1) / 2;
        pq.push(n / 2);
        M--;
    }
    cout << sum << endl;
    return 0;
}
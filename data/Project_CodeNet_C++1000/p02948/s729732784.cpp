#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N, M;
    cin >> N >> M;
    vector<pii> v(N);
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v[i] = pii(a, b);
    }
    sort(v.begin(), v.end());

    priority_queue<int> pq;
    int ans = 0;
    int j = 0;
    for (int i = 1; i <= M; i++) {
        for ( ; j < N && v[j].first <= i; j++) pq.push(v[j].second);
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';
}

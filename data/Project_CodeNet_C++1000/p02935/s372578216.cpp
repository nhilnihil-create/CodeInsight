#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using iii = pair<ii, int>;
#define vt vector
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define __lcm(a, b) a * b / __gcd(a, b)
const int MOD = 1e9 + 7;
const int INF = 2e9;
const int N = 1e2 + 5;

int n;
double x, a, b;
priority_queue<double, vt<double>, greater<double>> pq;

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        pq.push(x);
    }
    while(pq.size() > 1) {
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        pq.push((a + b) / 2);
    }
    cout << setprecision(5) << pq.top() << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    
}
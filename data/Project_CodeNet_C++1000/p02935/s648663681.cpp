#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int n;
    cin >> n;
    priority_queue<double, vector<double>, greater<double>> que;
    for (int i = 0; i < n; ++i) {
        double v;
        cin >> v;
        que.push(v);
    }
    for (int i = 0; i < n-1; ++i) {
        double x = que.top();
        que.pop();
        double y = que.top();
        que.pop();
        que.push((x + y) / 2.0);
    }
    cout << fixed << setprecision(10) << que.top() << endl;
}
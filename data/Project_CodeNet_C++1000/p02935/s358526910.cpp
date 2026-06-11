#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    priority_queue<double> q;
    rep(i,n){
        double vin;
        cin >> vin;
        q.push(-vin);
    }
    while(q.size() >= 2){
        double d = 0;
        d += -1 * q.top();
        q.pop();
        d += -1 * q.top();
        q.pop();
        q.push(-1 * ((double)d / 2));
    }
    double ans = -1 * q.top();
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}

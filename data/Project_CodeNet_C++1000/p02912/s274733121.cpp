#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<int> pq;
    rep(i, n) {
        int a;
        cin >> a;
        pq.push(a);
    }
    rep(i, m) {
        int a = pq.top();
        pq.pop();
        a /= 2;
        pq.push(a);
    }
    ll ans = 0;
    int c = pq.size();
    rep(i, c) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;

    return 0;
}
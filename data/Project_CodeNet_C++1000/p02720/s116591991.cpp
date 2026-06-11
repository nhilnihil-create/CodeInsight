#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

template<typename T>
void print(const vector<T> &x) {
    int n = x.size();
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x) {
    int n = x.size();
    rep(i,n) {
        rep(j,x[i].size()) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void print(const vector<T> &x, int n) {
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x, int n, int m) {
    rep(i,n) {
        rep(j,m) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void input_init() {
    cin.tie(0); ios::sync_with_stdio(false);
}

int main(int argc, char const *argv[]) {
    int k; cin>>k;
    vector<ll> lun;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 1; i < 10; ++i) pq.push(i);

    while (!pq.empty()) {
        if (lun.size() > k+100) break;
        ll cur = pq.top(); pq.pop();
        lun.push_back(cur);

        ll a = cur%10;
        ll nxt_p = (a+1)%10;
        ll nxt_m = (a-1)%10;
        ll nxt_z = a;
        if (a != 9) pq.push(cur*10+nxt_p);
        if (a != 0) pq.push(cur*10+nxt_m);
        pq.push(cur*10+nxt_z);
    }

    sort(lun.begin(), lun.end());
    cout << lun[k-1] << '\n';

    return 0;
}
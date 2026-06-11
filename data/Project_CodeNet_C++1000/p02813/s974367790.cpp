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
    vector<int> p(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
    }

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i+1;
    }
    int cnt = 0;
    int a, b;
    bool flag;
    do{
        cnt++;
        flag = true;
        for (int i = 0; i < n; ++i) {
            if (v[i] != p[i]) flag = false;
        }
        if (flag) a = cnt;

        flag = true;
        for (int i = 0; i < n; ++i) {
            if (v[i] != q[i]) flag = false;
        }
        if (flag) b = cnt;
    } while(next_permutation(all(v)));

    cout << abs(a-b) << endl;
}
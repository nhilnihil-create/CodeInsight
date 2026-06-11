#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int n;
    cin >> n;
    vector<int> v(n, 0);
    int a;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a;
        v[a-1]++;
    }
    for (int i = 0; i < n; ++i) {
        cout << v[i] << endl;
    }
}
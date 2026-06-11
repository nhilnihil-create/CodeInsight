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
    int n, x, y;
    cin >> n >> x >> y;
    x--; y--;
    map<int, int> mp;
    int tmp;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            tmp = min({j-i, abs(i-x) + abs(j-y) + 1, abs(i-y) + abs(j-x) + 1});
            mp[tmp]++;
        }
    }
    for (int i = 1; i < n; ++i) {
        cout << mp[i] << endl;
    }
}
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
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    sort(all(l));

    int res = 0;
    for (int i = 0; i < n-2; ++i) {
        for (int j = i+1; j < n-1; ++j) {
            for (int k = j+1; k < n; ++k) {
                if (l[i] + l[j] > l[k]) res++;
            }
        }
    }
    cout << res << endl;
}
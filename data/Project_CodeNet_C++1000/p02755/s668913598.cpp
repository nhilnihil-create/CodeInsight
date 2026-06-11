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
    int a, b;
    cin >> a >> b;
    int res = -1;
    for (int i = 1; i <= 2000; ++i) {
        if ((int)(i * 0.08) == a && (int)(i * 0.10) == b){
            res = i;
            break;
        }
    }
    cout << res << endl;
}
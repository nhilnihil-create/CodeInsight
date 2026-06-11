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
    int k, a, b;
    cin >> k >> a >> b;
    for (int i = a; i <= b; ++i) {
        if (i % k == 0){
            cout << "OK" << endl;
            return 0;
        }
    }
    cout << "NG" << endl;
}
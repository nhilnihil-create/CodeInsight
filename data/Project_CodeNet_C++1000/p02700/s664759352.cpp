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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    while(1){
        c -= b;
        if (c <= 0){
             cout << "Yes" << endl;
             return 0;
        }

        a -= d;
        if (a <= 0){
            cout << "No" << endl;
            return 0;
        }
    }
}
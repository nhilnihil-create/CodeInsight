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
    int x;
    cin >> x;
    ll limit = 1000; // (x+1)^5 - x^5 > 10^9
    ll a, b;
    for(a = -limit; a <= limit; ++a){
        for(b = -limit; b <= limit; ++b){
            if (pow(a, 5) - pow(b, 5) == x){
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
}
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
    ll a, b, k;
    cin >> a >> b >> k;
    if (k >= a + b){
        cout << 0 << " " << 0 << endl;
    } else if (k >= a){
        cout << 0 << " " << b - (k-a) << endl;
    } else{
        cout << a-k << " " << b << endl;
    }
}
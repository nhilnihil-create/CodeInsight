#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl;
#define INF 1ll<<60;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;
using ll = long long;
typedef pair<int, int> P;

int main(){
    int n, l; cin >> n >> l;
    int a[n];

    int t, su=0, mi=10000000;
    rep(i, n){
        a[i] = l+i;
        su+=a[i];
        if(mi>abs(a[i])){
            mi = abs(a[i]);
            t = a[i];
        }
    }
    out(su-t);
}
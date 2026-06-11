#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    
    ll pre = 0;
    rep(i,n){
        if(pre < h[i]){
            pre = h[i] - 1;
        } else if(pre > h[i]){
            cout << "No" << endl;
            return 0;
        } else {
            pre = h[i];
        }
    }
    cout << "Yes" << endl;
    return 0;
}

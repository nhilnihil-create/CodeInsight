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
    int n,q;
    ll k;
    cin >> n >> k >> q;
    vector<int> cnt(n, 0);
    rep(i, q){
        int a;
        cin >> a;
        cnt[a-1]++;
    }
    ll border = k - q;
    rep(i,n){
        if(border + cnt[i] > 0){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}

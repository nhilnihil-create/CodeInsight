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
    int n, ans;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    ans = 0;
    for(int i = 1; i < n - 1; i++){
        if((p[i] > p[i-1] && p[i] < p[i+1]) || (p[i] < p[i-1] && p[i] > p[i+1])){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

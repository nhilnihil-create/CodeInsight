#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


int main(){
    int n;
    cin >> n;
    int cnt = 0;
    rep(i, n){
        string s = to_string(i+1);
        if (s.size()%2 == 1) cnt++;
    }
    cout << cnt << endl;
    return 0;
}

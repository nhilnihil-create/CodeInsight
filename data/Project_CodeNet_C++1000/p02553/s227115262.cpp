#include <bits/stdc++.h>
 
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> P;
 
constexpr int INF = 1e9;
constexpr int MOD = 1e9+7;

int main() {
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll ans = max({
        a*c,a*d,b*c,b*d
    });
    cout << ans << endl;
    return 0;
}
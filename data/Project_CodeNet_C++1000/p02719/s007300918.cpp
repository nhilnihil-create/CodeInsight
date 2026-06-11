#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
int inf = 1000000000; //10e9
ll linf = 1000000000000000000; //10e18
 
int main() {

    ll N, K;
    cin >> N >> K;

    ll ans = min(N%K, K - N%K);

    cout << ans << endl;

    return 0;

}
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
#define MOD 1000000007
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<int> dp(1 << N, pow(10, 9));

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ll x = 0;
        for(int j = 0; j < b; j++) {
            ll c;
            cin >> c;
            x += 1LL << (c - 1LL);
        }
        for(ll bit = 1LL; bit < (1LL << N); bit++) {
            if((bit & x) == bit) {
                dp[bit] = min(dp[bit], a);
            }
        }
    }

    for(ll bit = 1LL; bit < (1LL << N); bit++) {
        for(int i = 1LL; i < bit; i++) {
            if((bit & i) == i) {
                dp[bit] = min(dp[bit], dp[bit - i] + dp[i]);
            }
        }
    }

    if(dp[(1 << N) - 1LL] == pow(10, 9)) {
        cout << -1 << endl;
    } else {
        cout << dp[(1 << N) - 1LL] << endl;
    }
}
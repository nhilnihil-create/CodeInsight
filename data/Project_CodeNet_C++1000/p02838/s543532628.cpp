// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N), digit(64, 0);
    rep(i, N) cin >> A[i];

    rep(i, N){
        bitset<64> s(A[i]);
        rep(j, 64){
            if(s.test(j)) digit[j]++;
        }
    }

    ll ans = 0, a = 1;

    rep(i, 64){
        ll tmp = (N - digit[i]) * digit[i];
        tmp %= INF;
        tmp *= a;
        tmp %= INF;

        ans += tmp;
        ans %= INF;
        a *= 2;
        a %= INF;
    }

    cout << ans << endl;
    
}
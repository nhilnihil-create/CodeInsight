#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    ll N; cin >> N;
    if(N%2 == 1){
        cout << 0 << endl;
        return 0;
    }
    string s = to_string(N);
    int ss = s.size();
    
    ll ans = 0;
    ll now5 = 10;
    while(now5 <= N){
        ll x = N / now5;
        ans += x;
        now5 *= 5;
    }

    cout << ans << endl;

    return 0;
}
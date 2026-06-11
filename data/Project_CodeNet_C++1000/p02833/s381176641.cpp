#include <bits/stdc++.h>
#define INF 1e9
#define MOD 1000000007
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main(void) {
    ll N;
    cin >> N;

    if(N%2 == 1){
        cout << 0 << endl;
        return 0;
    } else {
        ll ans = 0;
        ll div = 10;

        while (N >= div)
        {
            ans += N / div;            
            div *= 5;
        }
        cout << ans << endl;
    }
    
    return 0;
}

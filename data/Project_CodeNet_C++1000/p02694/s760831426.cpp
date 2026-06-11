#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long double ld;
typedef long long ll;
const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;


int main() {
    ll x; cin >> x;

    ll tmp = 100;
    ll cnt = 0;
    while(1){
        tmp += (tmp / 100);
        cnt++;
        if(tmp >= x){
            cout << cnt << endl;
            return 0;
        }
    }

    return 0;
}

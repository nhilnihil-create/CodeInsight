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
    ll n, k, s; cin >> n >> k >> s;

    ll s2 = s;
    if(s == 1e9) s2--;
    else s2++;

    for(int i = 0; i < n; i++){
        if(0 < k){
            cout << s << endl;
            k--;
        }else{
            cout << s2 << endl;
        }
    }

    return 0;
}

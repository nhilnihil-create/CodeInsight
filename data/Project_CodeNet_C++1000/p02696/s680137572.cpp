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
    ll a, b, n; cin >> a >> b >> n;
    if(n < b){
        cout << (a * n) / b << endl;
    }else{
        cout << (a * (b - 1)) / b << endl;
    }

    return 0;
}

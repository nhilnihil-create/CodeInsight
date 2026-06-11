#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    ll x, k, d;
    cin >> x >> k >> d;
    x = abs(x);

    if (x / d > k){
        cout << x - k * d << endl;
    } else{
        k -= x/d;
        x -= x/d * d;

        cout << ((k % 2) ? d - x : x) << endl;
    }
}
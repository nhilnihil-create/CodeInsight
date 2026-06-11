#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    int res = 0;
    if (k < a) res = k;
    else{
        k -= a;
        if (k < b) res = a;
        else{
            k -= b;
            res = a - k;
        }
    }
    cout << res << endl;
}
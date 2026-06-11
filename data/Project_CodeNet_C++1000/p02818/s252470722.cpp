#include <iostream>
#include <algorithm>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    b = max(0LL, min(b, b-(k-a)));
    a = max(0LL, a-k);
    cout << a << " " << b << endl;

    return 0;
}

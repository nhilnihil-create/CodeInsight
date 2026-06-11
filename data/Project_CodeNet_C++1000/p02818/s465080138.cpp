#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    if(a >= k) cout << a-k << " " << b << endl;
    else if(a + b <= k) cout << "0 0" << endl;
    else cout << "0 " << b - (k - a) << endl;
    return 0;
}
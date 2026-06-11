#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll a;
    string sb;
    cin >> a >> sb;
    ll b = 100 * (sb[0] - '0') + 10 * (sb[2] - '0') + (sb[3] - '0');
    ll ans = a * b;
    ans /= 100;
    cout << ans << endl;
    return 0;
}
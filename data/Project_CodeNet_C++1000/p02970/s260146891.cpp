#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, d;
    cin >> n >> d;
    ll ans = (n + 2*d)/(2 * d + 1);
    cout << ans << endl;
    return 0;
}
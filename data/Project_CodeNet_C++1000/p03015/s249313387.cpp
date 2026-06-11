#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    string L;
    cin >> L;
    ll dp0 = 0;
    ll dp1 = 1;
    for(int i=0; i<L.size(); i++){
        ll dp0n = 0;
        ll dp1n = 0;
        if(L[i] == '1'){
            dp0n = 1 * dp1;
            dp1n = 2 * dp1;
        }else{
            dp1n = 1 * dp1;
        }
        dp0n += 3 * dp0;
        swap(dp0, dp0n);
        swap(dp1, dp1n);
        dp0 %= 1000000007;
        dp1 %= 1000000007;
    }
    auto res = dp0 + dp1;
    res %= 1000000007;
    cout << res << endl;

    return 0;
}
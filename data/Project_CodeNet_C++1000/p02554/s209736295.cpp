#include <bits/stdc++.h>
using namespace std;
long long const MX = 2e5 + 2, MOD = 1e9 + 7;
long long power(long long a, long long n){
    long long s = 1;
    for(int i = 0; i < n; i++)
        s = (s * a) % MOD;
    return s;
}
int main()
{
    int t= 1;
//    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long ans = power(10, n) - (((2 *power(9, n) - power(8, n)) % MOD > 0 ? (2 *power(9, n) - power(8, n)) % MOD : (2 *power(9, n) - power(8, n)) % MOD + MOD));
        //cout<<ans<<"\n";
        if(ans < 0) ans += MOD;
        ans = ans % MOD;
        cout<<ans;
    }
}



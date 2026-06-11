#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<fstream>

#define MOD (1000000007)

using namespace std;

typedef long long int Int;

constexpr Int TEN(int n) { return n == 0 ? 1 : 10 * TEN(n-1); }

const int max_K = 100000+10;

Int N,K;
Int dp[max_K];

Int mod_pow(Int x, Int r) {
    if(r == 0)
        return 1;

    Int ans = mod_pow(x*x%MOD,r>>1);
    if(r&1)
        ans = (ans*x)%MOD;
    
    return ans%MOD;
}

int main(void) {
    cin>>N>>K;

    Int ans = 0;
    for(Int d = K;d >= 1;d--) {
        Int n2 = 0;
        Int x = K/d;
        Int num = mod_pow(x,N);
        
        dp[d] = num;
        
        for(Int i = 2;i*d <= K;i++) {
            dp[d] = (MOD + dp[d] - dp[i*d])%MOD;
        }

        ans += d*dp[d]%MOD;
        ans %= MOD;
    }

    cout<<ans<<endl;

    return 0;
}

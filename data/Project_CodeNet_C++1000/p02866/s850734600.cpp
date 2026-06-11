typedef long long ll;
#include <bits/stdc++.h>
using namespace std;


int main() {
    ll n;
    std::cin >> n;
    vector<ll> d(n);
    for (int i = 0; i < n; i++) {
        std::cin >> d[i];
    }
    if(d[0]!=0){
        std::cout << 0 << std::endl;
        return 0;
    }
    sort(d.begin(),d.end());
    
    vector<ll> dp(n,0);
    
    
    ll res = 1;
    dp[0]++;
    for (int i = 1; i < n; i++) {
        if(d[i]==0){
            std::cout << 0 << std::endl;
            return 0;
        }
        
        res *= dp[d[i]-1];
        res %= 998244353;
        
        dp[d[i]]++;

        if(res==0){
            std::cout << 0 << std::endl;
            return 0;
        }
    }
    std::cout << res << std::endl;
}

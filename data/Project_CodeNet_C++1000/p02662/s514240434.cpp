#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int main()
{
    int n ,s;
    scanf("%d%d",&n,&s);
    vector <int> a(n);
    for(int&i : a)
        scanf("%d",&i);

    vector <int> dp(s+1);
    dp[0] = 1;
    for(int&x : a){
        for(int j=s; ~j; j--){
            dp[j] = (dp[j]+dp[j])%mod;
            if(j >= x)
                dp[j] = (dp[j]+dp[j-x])%mod;
        }
    }

    printf("%d\n",dp[s]);
}

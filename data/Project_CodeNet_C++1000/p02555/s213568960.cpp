#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stdlib.h>
#include<stack>
using namespace std;
#define PI 3.14159265358979
typedef  long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#include<set>
ll mod = 1000000007;
vector<ll> dp(2005);

ll sumdp(int p)
{   
    ll sum=0;
    for(int i=0;i<p;i++)
    {
        sum += dp[i];
        sum = sum%mod;
    }

    return sum;
}

int main(void)
{
    
    
    dp[0]=1;
    int s;
    cin>>s;

    for(int i=1;i<=s;i++)
    {
        if(i<3) dp[i]=0;

        dp[i] = sumdp(i-2);

    }

    cout<<dp[s]%mod<<endl;
}
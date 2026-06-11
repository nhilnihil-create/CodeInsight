#include<iostream>
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
ll mod=pow(10,9)+7;

int main(){
    string L;cin>>L;
    int N=L.size();
    mat dp(2,vec(N+1));
    dp[0][1]=1,dp[1][1]=2;
    for(int i=2;i<=N;i++){
        if(L[i-1]=='0'){
            dp[0][i]=((2*dp[0][i-1])%mod+dp[0][i-1])%mod;
            dp[1][i]=dp[1][i-1];
        }
        else{
            dp[0][i]=(((2*dp[0][i-1])%mod+dp[0][i-1])%mod+dp[1][i-1])%mod;
            dp[1][i]=(2*dp[1][i-1])%mod;
        }
    }
    cout<<(dp[0][N]+dp[1][N])%mod<<endl;
    return 0;
}
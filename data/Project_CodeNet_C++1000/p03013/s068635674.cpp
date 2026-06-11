#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,M;
ll s[100001];
ll dp[100001];

int main(){
    cin>>N>>M;
    rep(i,M){
        ll a;
        cin>>a;
        s[a]++;
    }

    dp[0]=1;
    if(s[1]!=1) dp[1]=1;
    for(int i=2;i<=N;i++){
        if(s[i]!=1) dp[i]=dp[i-1]+dp[i-2];
        dp[i]%=MOD;
    }

    cout<<dp[N]<<endl;
}
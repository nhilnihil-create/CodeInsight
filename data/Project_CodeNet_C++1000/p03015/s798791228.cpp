#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <string>
#include <functional>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <bitset>
#define mp make_pair
#define YES cout<<"YES"<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define No cout<<"No"<<endl
#define rep(i,n) for(int i=0;i<n;i++)
#define INF (1<<30)
#define LLINF (1LL<<60)
//#define MOD 998244353
#define MOD 1000000007
#define PI 3.14159265358979
using ll = long long;
using namespace std;

int dp[100005][2];

int main(){
    string s;
    cin>>s;
    int n=s.size();
    dp[0][0]=1;
    rep(i,s.size()){
        if(s[i]=='0'){//a+bのi桁目が0
            dp[i+1][0]=dp[i][0];
            dp[i+1][1]=dp[i][1];
        }
        else{
            dp[i+1][1]=(dp[i][0]+dp[i][1])%MOD;
        }

        if(s[i]=='0'){//a+bのi桁目が1
            dp[i+1][1]+=dp[i][1]*2%MOD;
            dp[i+1][1]%=MOD;
        }
        else{
            dp[i+1][0]+=dp[i][0]*2%MOD;
            dp[i+1][0]%=MOD;
            dp[i+1][1]+=dp[i][1]*2%MOD;
            dp[i+1][1]%=MOD;
        }
    }
    int ans=(dp[n][0]+dp[n][1])%MOD;
    cout<<ans<<endl;
    return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;

int dp[5005][5005];

int main(void){
    int n;
    string s;
    cin>>n>>s;
    int res=0;
    for(int r=n-1;r>0;r--){
        for(int l=r-1;l>=0;l--){
            if(s[r]==s[l])dp[l][r]=max(dp[l][r],dp[l+1][r+1]+1);
            res=max(res,min(dp[l][r],r-l));
        }
    }
    cout<<res<<endl;
    return 0;
}
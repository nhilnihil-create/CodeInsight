#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=4999999996000000001;
int dp[6001][6001];

int main(){
    int n;
    string s;
    cin>>n>>s;
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(s[i]!=s[j]) continue;
            dp[i][j]=dp[i+1][j+1]+1;
            //cout<<"i="<<i<<"j="<<j<<" : "<<dp[i][j]<<endl;
        }
    }
    int ans=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int buf=min(dp[i][j],j-i);
            ans=max(ans,buf);
        }
    }
    cout<<ans<<endl;
}
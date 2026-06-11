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
typedef pair<int,int> P;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
ll dp[1000100][2];


int main(){
    string s;
    cin>>s;
    s='0'+s;
    int n=s.length();

    for(int i=0;i<n+3;i++){
        dp[i][0]=INF;
        dp[i][1]=INF;
    }

    dp[n-1][0]=s[n-1]-'0';
    dp[n-1][1]=10-(s[n-1]-'0');

    for(int i=n-1;i>0;i--){
        int now=s[i-1]-'0';

        /// keta=0
        for(int a=0;a<10;a++){
            int b=a-now;
            if(b<0){
                b+=10;
                dp[i-1][1]=min(dp[i-1][1],dp[i][0]+a+b);
            }else{
                dp[i-1][0]=min(dp[i-1][0],dp[i][0]+a+b);
            }
        }
        /// keta=1
        for(int a=-1;a<9;a++){
            int b=a-now;
            if(b<0){
                b+=10;
                dp[i-1][1]=min(dp[i-1][1],dp[i][1]+a+b+1);
            }else{
                dp[i-1][0]=min(dp[i-1][0],dp[i][1]+a+b+1);
            }
        }

    }

    cout<<dp[0][0]<<endl;
    
}
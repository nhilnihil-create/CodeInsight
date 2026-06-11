#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <numeric>
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<n;++i)
#define mrep(i,n) for(ll i=n;i>=0;--i)
#define all(a) (a).begin(),(a).end()
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define vb vector<bool>
#define vvb vector<vector<bool> >
#define pl pair<ll,ll>
#define inf 1001001001001000
#define mod 1000000007
#define pi 3.1415926535
using namespace std;

ll dp[100005][2];

int main(void){
    string l;
    cin>>l;
    dp[0][0] = 1;
    rep(i,l.size()){
        if(l[i] == '0'){
            dp[i+1][1] = (dp[i][1] + 2*dp[i][1]) % mod;
            dp[i+1][0] = dp[i][0];
        }
        else{
            dp[i+1][1] = (3*dp[i][1]+dp[i][0])%mod;
            dp[i+1][0] = (2*dp[i][0])%mod;
        }
    }
    cout<<(dp[l.size()][0]+dp[l.size()][1])%mod<<endl;
}
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
const ll INF=1<<18;

int main(){
    int n,m;
    cin>>n>>m;
    vector<bool> a(n+1,true);
    for(int i=0;i<m;i++){
        int b;
        cin>>b;
        a[b]=false;
    }

    vector<ll> dp(n+3,0);
    dp[0]=1;

    for(int i=0;i<=n;i++){
        if(a[i+1]) dp[i+1]+=dp[i];
        if(a[i+2]) dp[i+2]+=dp[i];
        dp[i+1]%=MOD;
        dp[i+2]%=MOD;
    }
    cout<<dp[n]<<endl;

}
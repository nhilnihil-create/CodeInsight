
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#include<string>
using namespace std;
#define ll long long
typedef pair<ll , ll > pii;
ll mod=998244353;
ll p=1e9+7;

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    int h,w; cin>>h>>w;
    int a[100][100];
    for(int i=0; i<h; i++){
        string s; cin>>s;
        for(int j=0; j<w; j++){
            if(s[j] == '#') a[i][j]=1;
            else a[i][j]=0;
        }
    }
    int dp[100][100];
    dp[0][0]=a[0][0];
    for(int i=1; i<w; i++){
        if(a[0][i] == 0) dp[0][i]= dp[0][i-1];
        else{
            dp[0][i]=dp[0][i-1]+(a[0][i-1] == 0);
        }
    }
    for(int i=1; i<h; i++){
        if(a[i][0] == 0) dp[i][0]= dp[i-1][0];
        else{
            dp[i][0]=dp[i-1][0]+(a[i-1][0] == 0);
        }
    }
    for(int i=1; i<h; i++){
        for(int j=1; j<w; j++){
            if( a[i][j] == 0 ) dp[i][j]=min(dp[i][j-1], dp[i-1][j]);
            else dp[i][j]=min( dp[i-1][j]+ (a[i-1][j] == 0) , dp[i][j-1]+ (a[i][j-1] == 0 ));

        }
    }
    int ans=dp[h-1][w-1];
    cout<<ans<<endl;
    return 0;
}

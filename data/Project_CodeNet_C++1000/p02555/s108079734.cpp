#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <math.h>
#include <queue>
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;

const ll mod = 1000000007;

int main() {
    int s;
    cin >> s;
    vector<int> dp(s+1);
    dp[0]=1;
    for(int i=1; i<=s; ++i) {
        for(int j=0; j<=i-3; ++j) {
            dp[i]+=dp[j];
            dp[i]%=mod;
        }
    }
    cout << dp[s] << endl;
    return 0;
}
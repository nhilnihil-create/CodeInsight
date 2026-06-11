#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <limits>
#include <iomanip>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    string S;
    cin >> S;
    int size =S.size();
    vector<int> dp(size+1);
    for(int i=0;i<=size-1;i++){
        if(S[i]=='<'){
            dp[i+1]=dp[i]+1;
        }
    }
    for(int i=size-1;i>=0;i--){
        if(S[i]=='>'){
            dp[i]=max(dp[i],dp[i+1]+1);
        }
    }
    ll ans=0;
    for(int i=0;i<=size;i++){
        ans = ans + dp[i];
    }
    cout << ans << endl;
}
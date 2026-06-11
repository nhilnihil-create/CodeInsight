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
    int N;
    cin >> N;
    vector<int> A(N);
    vector<ll> dp(N+1);
    for(int i=0;i<N;i++){
        cin >> A[i];
        dp[A[i]]++;
    }
    ll total=0;
    for(int i=1;i<=N;i++){
        if(dp[i]>1){
            total+= (dp[i]*(dp[i]-1))/2;
        }
    }
    for(int i=0;i<N;i++){
        int num = A[i];
        ll ans=total;
        if(dp[num]>1){
            ans = ans - (dp[num]*(dp[num]-1))/2;
            if(dp[num]>2){
                ans +=((dp[num]-1)*(dp[num]-2))/2;
            }
        }
        cout << ans << endl;
    }
}
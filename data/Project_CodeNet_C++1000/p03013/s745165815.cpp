#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <climits> // FOO_MAX, FOO_MIN
#include <cmath> 
#include <cstdlib> // abs(int)

#define roundup(n,d) ( ((n) + ((d)-1)) / (d) )
#define ll long long
#define assign_max(into, compared) (into = max((into), (compared))) 

using namespace std;

int main(void){
    int N,M;
    cin >> N >> M;
    vector<bool> is_broken (N, false);
    for(int i = 0;i < M;i++){
        int job;
        cin >> job;
        is_broken[job] = true;
    }
    vector<ll> dp (N+1, 0);
    dp[0] = 1;
    for(int i = 0;i < N;i++){
        if(i+1 <= N && !is_broken[i+1]) dp[i+1] = (dp[i+1] + dp[i]) % 1000000007;
        if(i+2 <= N && !is_broken[i+2]) dp[i+2] = (dp[i+2] + dp[i]) % 1000000007;
    }
    cout << dp[N] << endl;
}
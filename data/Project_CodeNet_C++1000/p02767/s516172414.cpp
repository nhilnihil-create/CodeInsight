#include <bits/stdc++.h>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int N;
    cin >> N;
    int X[N];
    int min = 101;
    int max = 0;
    for(int i=0; i<N; i++){
        cin >> X[i];
        if (min > X[i]){min=X[i];}
        if (max < X[i]){max=X[i];}
    }

    int nums = int(max-min+1);
    int dp[nums];
    int dp_linear[nums];

    dp[0] = 0;
    dp_linear[0]=0;
    for(int j=0; j<N; j++){
        dp[0] += pow((X[j] -min),2);
        dp_linear[0] += (X[j] -min);
    }

    priority_queue<long, vector<long>, greater<long>> que;
    que.push(dp[0]);
    for(int k=1; k<nums; k++){
        dp[k] = dp[k-1] - 2*dp_linear[k-1] + N;
        dp_linear[k] = dp_linear[k-1] - N;
        que.push(dp[k]);
    }

    int ans = que.top();
    cout << ans << endl;
}
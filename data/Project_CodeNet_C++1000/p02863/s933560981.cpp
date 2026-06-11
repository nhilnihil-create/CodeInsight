#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 3005;
ll dp[MAX_N][2*MAX_N]={0};

int main(void){
    int n,t;
    cin >> n >> t;
    vector<pair<int,int>> dishes(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        dishes[i] = make_pair(a,b);
    }
    sort(dishes.begin(),dishes.end());

    dp[0][0] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<2*MAX_N;j++){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j-dishes[i].first>=0 && j-dishes[i].first<=t-1) dp[i+1][j] = max(dp[i+1][j], dp[i][j-dishes[i].first]+dishes[i].second);
        }
    }

    ll maxpoint = 0;
    for(int i=0;i<2*MAX_N;i++){
        if(maxpoint<dp[n][i]) maxpoint = dp[n][i];
    }
    cout << maxpoint << endl;
 }
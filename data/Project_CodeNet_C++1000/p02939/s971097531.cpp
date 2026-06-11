#include <bits/stdc++.h>
using namespace std;

void chmax(int& a, int b){
    a = max(a, b);
}

int main(){
    string S;
    cin >> S;
    int N = S.size();

    vector<vector<int>> dp(N+10, vector<int>(5, -1e9));
    dp[0][0] = 0;
    for(int i=0; i<N; i++) for(int j=0; j<=4; j++) for(int k=1; k<=4; k++){
        if(dp[i][j] >= 0 && S.substr(i-j, j) != S.substr(i, k)) chmax(dp[i+k][k], dp[i][j] + 1);
    }
    cout << *max_element(dp[N].begin(), dp[N].end()) << endl;
    return 0;
}

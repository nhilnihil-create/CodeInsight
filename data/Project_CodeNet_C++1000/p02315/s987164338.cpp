#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int main(){

    int n, w_max;
    cin>> n>> w_max;

    int dp[n+1][w_max+1];
    for(int i=0; i<n+1; i++){
        dp[i][0] = 0;
    }
    for(int j=0; j<w_max+1; j++){
        dp[0][j] = 0;
    }

    vector<pair<int, int> > item(n+1); //first:value, second:weigh
    for(int i=1; i<n+1; i++){
        cin>> item[i].first>> item[i].second;
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<w_max+1; j++){
            if(j<item[i].second){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-item[i].second]+item[i].first);
            }
        }
    }
    cout<< dp[n][w_max]<< endl;

    return 0;
}
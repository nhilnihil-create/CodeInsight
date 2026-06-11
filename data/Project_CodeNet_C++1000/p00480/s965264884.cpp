#include<iostream>
#include<vector>

using namespace std;

int main(){

    int n;
    cin>> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>> a[i];
    }

    long long dp[105][25];// [sequence][sum]:=
    fill(dp[0], dp[105], 0);// 

    dp[0][a[0]]=1;
    for(int i=1; i<n; i++){
        for(int j=0; j<=20; j++){
            if(j+a[i]<=20){
                dp[i][j+a[i]]+=dp[i-1][j];
            }
            if(j-a[i]>=0){
                dp[i][j-a[i]]+=dp[i-1][j];
            }

        }
    }

    cout<< dp[n-2][a[n-1]]<< endl;

    return 0;
}
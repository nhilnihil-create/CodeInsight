#include <iostream>
#include <string>
#include <vector>
using ll=long long;
using namespace std;

int main(){
    string S;
    cin>>S;

    vector<int> N;
    int size=S.size();
    for(int i=size-1;i>=0;i--){
        N.push_back((int)S[i]-'0');
    }
    N.push_back(0);
    size++;
    vector<vector<int>> dp(size+1,vector<int>(2,0));
    dp[0][0]=0;dp[0][1]=10;
    for(int i=0;i<size;i++){
        dp[i+1][0]=min(dp[i][0]+N[i],dp[i][1]+N[i]+1);
        dp[i+1][1]=min(dp[i][1]+9-N[i],dp[i][0]+10-N[i]);
    }

/*
    for(int i=0;i<size+1;i++){
        cout<<dp[i][0]<<" ";
    }
    cout<<endl;
    for(int i=0;i<size+1;i++){
        cout<<dp[i][1]<<" ";
    }
    cout<<endl;
    //*/
    

    cout<<dp[size][0]<<endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    string N;
    int counter=0;
    int count, counter1;
    cin >>N;
    int a[N.size()];
    for(int i=0;i<N.size();i++){
    a[i]=N.at(i)-'0';}
    int dp[1000010][2]{};
    dp[0][0]=a[0];
    dp[0][1]=11-a[0];
    for(int i=0;i<N.size()-1;i++){
    dp[i+1][0]=min(dp[i][0]+a[i+1],dp[i][1]+a[i+1]);
    dp[i+1][1]=min(dp[i][0]+11-a[i+1],dp[i][1]+9-a[i+1]);}                                  
    cout<<min(dp[N.size()-1][1],dp[N.size()-1][0])<<endl;}

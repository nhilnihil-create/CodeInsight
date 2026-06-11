#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long x;
    cin >> x;

    if(x < 100){
        printf("0\n");
        return 0;
    }

    if(x <= 105){
        printf("1\n");
        return 0;
    }

    bool dp[x+1];

    for(long long i = 0; i < 100; i++){
        dp[i] = false;
    }
    dp[100] = true;
    dp[101] = true;
    dp[102] = true;
    dp[103] = true;
    dp[104] = true;
    dp[105] = true;

    for(long long i = 106; i <= x; i++){
        if(dp[i-100] == true || dp[i-101] == true || dp[i-102] == true || dp[i-103] == true || dp[i-104] == true || dp[i-105] == true){
            dp[i] = true;
        }
        else{
            dp[i] = false;
        }
    }
    if(dp[x] == true){
        printf("1\n");
    }
    else{
        printf("0\n");
    }

    return 0;
}
#include <iostream>
using namespace std;
int dp[50];
int fib(int n){
        if(n<2)
                return 1;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=fib(n-1)+fib(n-2);
}
int main(){
        int N;
        for(int i=0 ; i<50 ; i++ )
                dp[i]=-1;
        cin >> N;
        cout << fib(N) << endl;
        return 0;
}

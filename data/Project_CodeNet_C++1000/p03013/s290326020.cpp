#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int N,M;
    cin >> N >> M;
    int a[N+1];
    for(int i=1;i<=N;i++)a[i]=1;
    for(int i=0;i<M;i++){
        int tmpa;
        cin >> tmpa;
        a[tmpa] = 0;
    }
    long long dp[N+1];
    dp[0] = 1;
    dp[1] = a[1];
    for(int i=2;i<=N;i++){
        if(a[i]){
            dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
        }
        else{
            dp[i] = 0;
        }
    }
    long long ans = dp[N];
    cout << ans;
}

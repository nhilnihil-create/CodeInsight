#include <bits/stdc++.h>
using namespace std;
 
string S; int N, cnt;
 
int main() {
	int N;
    cin >> N;
    int H[N+1];
    for(int i=1;i<=N;i++)cin >> H[i];
    int dp[N+1];
    dp[N]=0;
    int Ans=dp[N];
    for(int i=1;i<N;i++){
        if(H[N-i+1]<=H[N-i])dp[N-i]=dp[N-i+1]+1;
        else dp[N-i]=0;
        Ans=max(Ans,dp[N-i]);
    }
    cout << Ans << endl;
}
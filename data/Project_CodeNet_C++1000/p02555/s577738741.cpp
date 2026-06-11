#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long mod=1000000007;

int countSequence(int sum) {
    ll dp[2001];
    dp[0]=1;
    dp[1]=0;
    dp[2]=0;
    dp[3]=1;
    for(int i=4;i<=sum;i++) {
        ll total=0;
        for(int j=3;j<=i;j++) {
            total=(total+dp[i-j])%mod;
        }
        dp[i]=total;
    }
    return dp[sum];
}
int main() {
    int s;
    cin>>s;
    int size=s-3+1;
    int arr[size];
    int start=3;
    for(int i=0;i<size;i++) {
        arr[i]=start;
        start++;
    }

    int ans = countSequence(s);
    cout<<ans;
}

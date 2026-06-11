#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
#define NUM 1000000007
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n,m;
    cin>>n>>m;
    vector<bool> ok(n+1,true);
    rep(i,m){
        int a;
        cin>>a;
        ok[a]=false;
    }
    vector<ll> dp(n+1);
    dp[0]=1;
    rep(now,n){
        for(int next=now+1;next<=min(n,now+2);next++){
            if(ok[next]){
                dp[next]+=dp[now];
                dp[next]%=NUM;
            }
        }
    }
    cout<<dp[n];
}
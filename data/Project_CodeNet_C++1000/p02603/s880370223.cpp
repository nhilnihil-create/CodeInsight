#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, M;
void func()
{
    cin>>N;
    ll a[N];
    rep(i, 0, N)cin>>a[i];
    ll dp[N]={};
    dp[0]=1000;
    rep(i, 1, N) {
        dp[i]=dp[i-1];
        rep(j, 0, i) {
            dp[i]=max(dp[i], dp[j]+(a[i]-a[j])*(dp[j]/a[j]));
        }
    }
    cout<<dp[N-1]<<endl;
}

int main()
{
    func();
}
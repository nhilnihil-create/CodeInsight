#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    string s;
    cin >> s;
    set<string> st;
    ll n = s.size();

    if(n == 1){
        cout<<1<<endl;
        return 0;
    }
    if(n == 2){
        if(s[0] == s[1]) cout<<1<<endl;
        else cout<<2<<endl;
        return 0;
    }

    ll dp[n]{};
    dp[0] = 1;
    if(s[0] == s[1]) dp[1] = 1;
    else dp[1] = 2;
    if(s[0] != s[1] && s[1] != s[2]) dp[2] = 3;
    else dp[2] =2;
    for(int i=3; i<n; i++){
        if(s[i-1] == s[i]) dp[i] = dp[i-3] + 2;
        else dp[i] = dp[i-1] + 1;
    }

    cout << dp[n-1] << endl;
    return 0;
}
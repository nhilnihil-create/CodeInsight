#include <bits/stdc++.h>
using namespace std;
const long long MD=1e9+7;
long long n,dp[100005],pre[100005],ans;
vector<int> v;
string str;
long long qpow(long long b,long long exp) {
    long long ret=1;
    while (exp!=0) {
        if (exp%2==1) {ret*=b; ret%=MD;}
        b*=b; b%=MD;
        exp/=2;
    }
    return ret;
}
int main() {
    cin>>str; n=str.size();
    for (int i=0; i<n; i++) {
        if (str[i]=='1') v.push_back(n-i-1);
    }
    v.push_back(0);
    dp[0]=1;
    for (int i=1; i<=n; i++) dp[i]=qpow(3,i-1);
    for (int i=1; i<=n; i++) {pre[i]=pre[i-1]+dp[i]; pre[i]%=MD;}
    ans+=pre[n-1];
    for (int i=0; i<v.size()-1; i++) {
        ans+=((dp[v[i+1]+1]*qpow(2,i))%MD); ans%=MD;
    }
    cout<<(1+(2*ans)%MD)%MD<<'\n';
}
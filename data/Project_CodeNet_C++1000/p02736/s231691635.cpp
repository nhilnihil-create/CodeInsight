#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=1e6+5;
const int mod=2;
char buff[maxn];
int cnt[maxn],sum[maxn];
int main() {
    int n;cin>>n>>(buff+1);bool one=0;
    for(int i=1;i<=n;i++) {
        buff[i]-='1';if(buff[i]==1) one=1;
        if(i%2==0) cnt[i]=cnt[i/2]+1;
        sum[i]=sum[i-1]+cnt[i];
    }
    if(!one) for(int i=1;i<=n;i++) buff[i]/=2;
    int ans=0;
    for(int i=1;i<=n;i++) if(sum[n-1]==sum[i-1]+sum[n-i]) ans=ans+buff[i];
    ans%=2;
    cout<<ans*(one?1:2)<<endl;
    return 0;
}
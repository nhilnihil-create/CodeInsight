
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()
int main(){
    int x;cin>>x;
    int ans=0;
    int tmp=x;
    ans=tmp/500*1000;
    tmp=tmp%500;
    ans+=tmp/5*5;
    cout<<ans<<endl;
}
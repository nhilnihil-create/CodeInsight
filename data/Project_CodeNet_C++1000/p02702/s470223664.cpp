#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxm=2e5+5;
const int mod=2019;
char s[maxm];
int a[maxm];
int n;
signed main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        a[i]=s[i]-'0';
    }
    map<int,int>mark;
    mark[0]=1;
    int sum=0;
    int base=1;
    int ans=0;
    for(int i=n;i>=1;i--){
        sum=(sum+a[i]*base%mod)%mod;
        ans+=mark[sum];
        mark[sum]++;
        base=base*10%mod;
    }
    cout<<ans<<endl;
    return 0;
}
/*
对于s[l,r],如果是2019的倍数,那么满足:
s[l]*10^(n-l)%2019+
*/

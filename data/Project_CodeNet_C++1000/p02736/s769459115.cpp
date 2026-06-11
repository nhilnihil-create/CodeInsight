#define HAVE_STRUCT_TIMESPEC
#include<bits/stdc++.h>
using namespace std;
int a[1000007],c[1000007];
char s[1000007];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    cin>>s+1;
    --n;
    for(int i=1;i<=n;++i)
        a[i]=abs(s[i]-s[i+1]);
    int flag=0;
    for(int i=1;i<=n;++i)
        if(a[i]==1)
            flag=1;
    if(!flag)
        for(int i=1;i<=n;++i)
            a[i]>>=1;
    for(int i=1;i<=n;++i){
        int x=i;
        while(!(x&1))
            ++c[i],x>>=1;
        c[i]+=c[i-1];
    }
    int ans=0;
    for(int i=1;i<=n;++i)
        ans^=c[n-1]-c[i-1]-c[n-i]?0:(a[i]&1);
    if(!flag)
        ans<<=1;
    cout<<ans;
    return 0;
}

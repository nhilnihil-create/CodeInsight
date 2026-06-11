#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int n,a[N];LL s[N],ans,now;
int main(){
    scanf("%d",&n);
    for(int i=0;i<=n;i++)scanf("%d",&a[i]);
    for(int i=n;i;i--)s[i]=s[i+1]+a[i];
    for(int i=0;i<=n;i++){
        now=i?min(now*2,s[i]):1,ans+=now;
        if(now<a[i])puts("-1"),exit(0);
        now-=a[i];
    }
    cout<<ans;
    return 0;
}
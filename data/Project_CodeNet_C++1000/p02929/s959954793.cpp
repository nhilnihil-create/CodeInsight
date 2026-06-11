#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define maxn 500010
#define mod 1000000007
char s[maxn];
int a[maxn];
int p[maxn];
int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<2*n;i++){
        if(s[i]=='W') a[i]=1;
        else a[i]=0;
    }
    int l=0,r=0,cnt=0,f=1;
    ll ans=1;
    for(int i=0;i<2*n;i++){
        if((a[i]+cnt)%2==0){
            p[i]=0;
            l++;
            cnt++;
        }
        else{
            p[i]=1;
            r++;
            ans=ans*cnt%mod;
            cnt--;
        }
        if(cnt<0){
            f=0;
            break;
        }
    }
    //for(int i=0;i<2*n;i++) printf("%d",p[i]);
    //printf("\n");
    if(f==0||cnt!=0){
        printf("0\n");
        return 0;
    }
    for(int i=1;i<=n;i++){
        ans=ans*i%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
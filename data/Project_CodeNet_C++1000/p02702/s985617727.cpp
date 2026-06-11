#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
const int inf =1e9;
char s[maxn];
int cnt[3000];
int p[maxn];

int main(){
    cin>>s+1;
    int n=strlen(s+1);

    p[0]=1;
    for(int i=1;i<=n;i++)p[i]=p[i-1]*10%2019;


    int tmp=0;

    cnt[0]=1;
    for(int i=1;i<=n;i++){
        tmp*=10;
        tmp+=s[i]-'0';
        tmp%=2019;
        cnt[tmp*p[n-i]%2019]++;
    }

    ll ans=0;
    for(int i=0;i<2019;i++){
        if(cnt[i]){
        ans+=1ll*cnt[i]*(cnt[i]-1)/2;
        }
    }

    cout<<ans<<endl;

    return 0;
}


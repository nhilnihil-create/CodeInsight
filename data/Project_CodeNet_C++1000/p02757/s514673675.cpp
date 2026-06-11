#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,p,num[10005],now,tmp,pw;
typedef long long LL;
char s[N];
LL ans;
int f(char a){
    return a-'0';
}
int main(){
    cin>>n>>p;
    scanf("%s",s+1);
    num[0]=1;pw=1;
    if(p==2||p==5){
        for(int i=1;i<=n;++i)
            if((s[i]-'0')%p==0) ans+=(i);
        cout<<ans<<endl;
        return 0;
    }
    for(int i=n;i>0;i--){
        tmp=(now+pw*f(s[i]))%p;
        ans+=num[tmp];num[tmp]++;
        now=tmp;
        pw*=10;pw%=p;
    }
    cout<<ans<<endl;
}
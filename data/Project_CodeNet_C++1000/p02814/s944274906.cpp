#include<bits/stdc++.h>
using namespace std;
#define LL long long

LL gcd(LL a,LL b){return b==0?a:gcd(b,a%b);}
LL lcm(LL a,LL b){return a/gcd(a,b)*b;}
LL N,M,a[100010];
int main(){
    cin>>N>>M;
    LL g=1,ok=1;
    for(int i=1;i<=N;++i){
        cin>>a[i];
        a[i]/=2;
        if(i==1)g=a[i];
        g=lcm(g,a[i]);
        if(g>M)ok=0;
    }
    for(int i=1;i<=N;++i){
        if(g/a[i]%2==0){ok=0;break;}
    }
    if(!ok){
        cout<<0<<endl;
        return 0;
    }
    LL ans=0;
    LL b=M/g;
    ans=b/2;
    if(b&1)ans++;
    cout<<ans<<endl;
    return 0;
}
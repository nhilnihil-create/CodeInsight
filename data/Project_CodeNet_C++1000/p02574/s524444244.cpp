#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<ctime>
using namespace std;
#define ll long long 
#define il inline
const int maxn=1000010;
int a[maxn],n,tot[maxn];
int prime[maxn],notprime[maxn];
int d[maxn];
int prime_tot;
il int read(){
    int x=0,f=1; char ch=getchar();
    while (ch<'0'||ch>'9') ch=getchar();
    while (ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+ch-'0'; ch=getchar();
    }
    return x*f;
}
int gcd(int x,int y){
    return (!y)?x:gcd(y,x%y);
}
void linear_seive(){
    notprime[1]=1; d[1]=1;
    for (int i=2;i<=1000000;++i){
        if (!notprime[i]){
            prime[++prime_tot]=i; d[i]=i;
        }
        for (int j=1;j<=prime_tot&&i*prime[j]<=1000000;++j){
            notprime[i*prime[j]]=1;
            d[i*prime[j]]=prime[j];
            if (!(i%prime[j])){
                break;
            }
        }
    }
}
int main(){
    //int timer=clock();
    //freopen("in.txt","r",stdin);
    linear_seive();
    //cout<<"linear_seive:"<<clock()-timer<<endl;
    n=read();
    bool ok=true;
    for (int i=1;i<=n;++i){
        a[i]=read();
    }
    sort(a+1,a+1+n); 
    int ttmp=1; while (a[ttmp]==1) ++ttmp;
    if (n-ttmp+1>prime_tot) ok=false;
    //cout<<"read:"<<clock()-timer<<endl;
    for (int i=1;i<=n;++i){
        if (!ok) break;
        int s=a[i],tmp;
        while (s!=d[s]){
            tot[s]++; tot[d[s]]++;
            if (tot[s]>1||tot[d[s]]>1){
                ok=false; break;
            }else{
                tmp=d[s];
                while (s%tmp==0) s/=tmp;
            }
        }
        if (s!=1){
            ++tot[s];
            if (tot[s]>1) ok=false;
        }
    }
    //cout<<"check ok1:"<<clock()-timer<<endl;
    if (ok){
        printf("pairwise coprime");
        exit(0);
    }
    int gd=a[1];
    for (int i=2;i<=n;++i){
        gd=gcd(gd,a[i]);
        if (gd==1) break;
    }
    //cout<<"check ok2:"<<clock()-timer<<endl;
    if (gd==1) printf("setwise coprime");
    else printf("not coprime");
}
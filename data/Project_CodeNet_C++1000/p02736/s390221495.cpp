#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define ll long long 
#define il inline
const int maxn=1000010;
il int read(){
    char ch=getchar();
    while (ch<'0'||ch>'9') ch=getchar();
    return ch-'0';
}
int n,a[maxn];
int odd1,occured1,odd2;
int main(){
    scanf("%d",&n); n--;
    for (int i=0;i<=n;++i){
        a[i]=read()-1; if (a[i]==1) occured1=1;
    }
    for (int i=0;i<=n;++i){
        if ((i&n)==i){
            if (a[i]==1) {odd1^=1;}
            else if (a[i]==2) odd2^=1;
        }
    }
    if (odd1){printf("1"); exit(0);}
    if (odd2&&!occured1){printf("2"); exit(0);}
    printf("0");
    return 0;
}
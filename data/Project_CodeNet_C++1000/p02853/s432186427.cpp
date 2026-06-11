#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int val[]={0,300000,200000,100000};

int main(){

    int a,b;
    scanf("%d%d",&a,&b);
    int ans=0;
    if(a<=3) ans+=val[a];
    if(b<=3) ans+=val[b];
    if(a==1 && b==1) ans+=400000;
    printf("%d\n",ans);

    return 0;
}
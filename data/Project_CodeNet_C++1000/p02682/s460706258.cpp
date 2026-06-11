#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
   // 制約見て！！！デカかったらlong longにすること！
    int a,b,c,k;
    scanf("%d%d%d%d",&a,&b,&c,&k);
    if(k>a+b) printf("%d\n",a-(k-(a+b)));
    else if(k>a) printf("%d\n",a);
    else printf("%d\n",k);
}

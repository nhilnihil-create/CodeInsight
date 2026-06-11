#include<bits/stdc++.h>
using namespace std;

int m;
long long sum=0,ans=0;
int main(){
    scanf("%d",&m);
    while (m--){
        int u;
        long long v;
        scanf("%d%lld",&u,&v);
        sum+=u*v, ans+=v;
    }
    printf("%lld\n",(sum-1)/9+ans-1);
    return 0;
}
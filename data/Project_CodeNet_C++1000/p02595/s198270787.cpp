#include <cstdio>

#define ll long long

int main(){
    int n;
    ll d;
    scanf("%d %lld",&n,&d);

    d=d*d;

    int cnt=0;
    for(int i=0;i<n;i++){
        ll x,y;
        scanf("%lld %lld",&x,&y);
        if(x*x+y*y<=d) cnt++;
    }
    printf("%d\n",cnt);
}

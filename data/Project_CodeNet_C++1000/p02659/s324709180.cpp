#include <bits/stdc++.h>
using namespace std;
# define LL long long

int main(){
    LL a;
    float b;
    scanf("%lld%f",&a,&b);
    b=b*100;
    b=round(b); /* 1. b is still floating 2.Can use round(b) also*/
    // cout<<b<<"\n";
    int b_=b;
    LL ans=a*b_;
    ans/=100;
    printf("%lld",ans);
}
// 9899901000000100
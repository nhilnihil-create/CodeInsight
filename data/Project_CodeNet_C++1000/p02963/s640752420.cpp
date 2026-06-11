#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;


int main(){
    ll s,tmp;
    ll x1,x2,y1,y2,x3,y3;
    scanf("%lld",&s);
    tmp=(ll)ceil(sqrt(s));
    if(tmp*tmp==s){
        printf("0 0 %lld 0 0 %lld\n",tmp,tmp);
        return 0;
    }
    x2=tmp; y3=tmp;
    tmp=tmp*tmp-s;
    for(x3=1;;x3++){
        if(tmp%x3==0&&tmp/x3<=1000000000LL){
            y2=tmp/x3;
            break;
        }
    }
    printf("0 0 %lld %lld %lld %lld\n",x2,y2,x3,y3);
    return 0;
}

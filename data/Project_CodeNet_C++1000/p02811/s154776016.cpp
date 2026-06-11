#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
typedef long long ll;
int main()
{
    ll k,x;
    scanf("%lld%lld",&k,&x);
    if(k*500>=x){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}

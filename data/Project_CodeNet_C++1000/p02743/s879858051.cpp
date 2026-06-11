#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    if(c>a+b&&(c-a-b)*(c-a-b)>a*b*4) printf("Yes");
    else printf("No");
    return 0;
}
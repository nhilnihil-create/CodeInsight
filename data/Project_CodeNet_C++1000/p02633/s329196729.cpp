#include <bits/stdc++.h>
using namespace std;
int x;
int gcd(int x,int y){
    if(y==0)
        return x;
    return gcd(y,x%y);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
int main()
{
    scanf("%d",&x);
    printf("%d",lcm(x,360)/x);
    return 0;
}

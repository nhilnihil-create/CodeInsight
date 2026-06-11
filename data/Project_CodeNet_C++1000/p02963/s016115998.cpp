#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long s, x, y;
    cin>>s;
    x=sqrt(s);
    if(x*x==s) y=x;
    else if(x*(x+1)>=s) y=x+1;
    else y=++x;
    printf("0 0 %lld 1 %lld %lld", x, (x*y)-s, y);
}

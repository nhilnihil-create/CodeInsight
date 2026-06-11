#include<bits/stdc++.h>
using namespace std;
long long a,b,c;
int main()
{
    cin>>a>>b>>c;
    long long x=c-a-b;
    if(x>0&&4*a*b<x*x)
    puts("Yes");
    else puts("No");
}
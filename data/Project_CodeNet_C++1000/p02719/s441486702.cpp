#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,M,m,s,x,y;
    cin>>a>>b;
    s=min(a%b,b-(a%b));
    cout<<s;
return 0;}

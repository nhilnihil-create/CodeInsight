#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long k,x,i;
    cin>>k>>x;
    for(i=(x-k)+1;i<=x-1;i++)
        {cout<<i<<" ";}
    for(i=x;i<=x+k-1;i++)
        {cout<<i<<" ";}

return 0;}

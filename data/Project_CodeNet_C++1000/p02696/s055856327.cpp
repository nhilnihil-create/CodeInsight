#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,n;
    cin>>a>>b>>n;
    if(n<b)
        cout<<(a*n)/b;
    else
        cout<<(a*(b-1))/b;
}
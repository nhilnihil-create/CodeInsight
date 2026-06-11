#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    long long int a,b,ans;
    cin>>a>>b;
    ans=a*b;

    if(a==1 || b == 1)
    {
        cout << 1;
        return 0;
    }

    if(ans & 1)
        cout << (ans+1)/2;
    else
        cout<<ans/2;
    return 0;
}
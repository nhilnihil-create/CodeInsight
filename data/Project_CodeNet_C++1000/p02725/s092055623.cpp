// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int main()
{
    int k=0,n=0,i,ans=0,b=0;
    int a[1000000];
    scanf("%d",&k);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int s=a[1]-a[0];
    for(i=0;i<n-1;i++)
    {
        if(s<a[i+1]-a[i])
        {
        s=a[i+1]-a[i];
        }
    }
    b=a[0]+(k-a[n-1]);
    if(s<b)
    {
        s=b;
    }
    for(i=0;i<n-1;i++)
    {
        ans+=a[i+1]-a[i];
    }
    ans+=b;
    ans-=s;


    

    cout << ans << endl;
    
  return 0;
}

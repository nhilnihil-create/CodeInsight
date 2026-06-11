#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,k,ans=0;

    cin>>n>>k;
/// TLE
//    for(int i=0;i<n;i++)
//    {
//
//        ans=min(n,abs(n-k));
//        n=ans;
//    }
//
    //     cout<<ans;

    if(n%k==0)
    {
        cout<<0;
    }
    else
    {
        n%=k;
        cout<<min(n,k-n);
    }



  return 0;
}

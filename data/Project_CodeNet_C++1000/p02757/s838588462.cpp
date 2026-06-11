#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include <string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include<bits/stdc++.h>
#include <set>
#define ll   long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f3f3f3f3f3f
#define pi 3.1415926535898
#define N 200050
using namespace std;
char a[200050];
int c[200050];
int main()
{
    int n,p;
    cin>>n>>p;
    cin>>(a+1);
    long long int  ans=0;
    if(p==2||p==5)
    {
        for(int i=1; i<=n; i++)
        {
            if((a[i]-'0')%p==0)
                ans+=i;
        }
        cout<<ans<<endl;
        return 0;
    }
    int   t=1;
    int sum=0;
    c[0]=1;
    for(int i=n; i>=1; i--)
    {
        sum=(sum+(a[i]-'0')*t)%p;
        ans+=c[sum];
        c[sum]++;
        t=t*10%p;
    }
    cout<<ans<<endl;
    return 0;
}

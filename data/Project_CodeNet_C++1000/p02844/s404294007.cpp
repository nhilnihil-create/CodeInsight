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
#define inf 0x3f3f3f
#define pi 3.1415926535898
using namespace std;
const int mod=1e9+7;
int  c[5];
int  a[30500];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%1d",&a[i]);
    }
    ll sum=0;
    for(int i=0; i<10; i++)
    {
        c[1]=i;
        for(int j=0; j<10; j++)
        {
            c[2]=j;
            for(int k=0; k<10; k++)
            {
                c[3]=k;
                int ans=1;
                for(int t=0; t<n; t++)
                {

                    int  a1=a[t],b1=c[ans];
                    if(a1==b1)
                    {
                        ans++;
                    }
                    if(ans>3)
                    {
                        sum++;
                        break;
                    }
                }
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}

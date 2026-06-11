#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include <set>
#define ll long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f3f
#define pi 3.1415926535898
using namespace std;
int a[500050];
int main()
{
     int n,k;
     cin>>n;
     for(int i=0;i<n-1;i++)
     {
         cin>>k;
         a[k]++;
     }
     for(int i=1;i<=n;i++)
     {
         cout<<a[i]<<endl;
     }
    return 0;
}

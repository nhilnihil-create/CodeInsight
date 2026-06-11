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

int main()
{
   int x,y;
   cin>>x>>y;
   int a=max(x,y);
   int c=min(x,y);
   for(int i=0;i<a;i++)
   {
       cout<<c;
   }

    return 0;
}

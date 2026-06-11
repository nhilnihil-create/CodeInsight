#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <math.h>
#define ll long long
using namespace std;
//int main()
//{
//    int a[1005];
//    int n;
//    scanf("%d",&n);
//    for(int i=0;i<n;i++)
//        scanf("%d",&a[i]);
//    sort(a,a+n);
//    int l=0,r=n-1;
//    int flag=0;
//    while(l<r)
//    {
//        //printf("***");
//        int mx=0,mn=0;
//        int m=a[l]+a[r];
//        for(int i=0;i<n;i++)
//        {
//            if(i==r||i==l)
//                continue;
//           // printf("***");
//            if(a[i]+m==0)
//            {
//                flag=1;
//                printf("%d %d %d\n",a[l],a[i],a[r]);
//            }
//            mx=abs(a[i]+m);
//            if(a[i]+m>0)
//                mn=1;
//            else if(a[i]+m<0)
//                mn=-1;
//        }
//        if(mn==-1)
//            l++;
//        if(mn==1)
//            r--;
//    }
//    if(flag==0)
//    {
//        printf("No Solution\n");
//    }
//    return 0;
//}


int main()
{
   int n;
   ll sum=0,sum1=0;
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
       sum+=i;
       if(i%3==0||i%5==0)
        sum1+=i;

   }
   printf("%lld\n",sum-sum1);
   return 0;
}


#include <iostream>
#include <bits/stdc++.h>
#include<climits>
using namespace std;
int main()
{
   int n;
   cin>>n;
   long sum[n+1];
   long diff[n+1];
   for(int i =0;i<n;i++)
   {
       long a,b;
       cin>>a>>b;
       sum[i] = a+b;
       diff[i] = a-b;
    }
    long maxi = LONG_MIN;
    long mini = LONG_MAX;
    for(int i=0;i<n;i++)
    {
       maxi = max(maxi,sum[i]);
       mini = min(mini,sum[i]);
    }
     long ans1 = maxi - mini;
    maxi = LONG_MIN;
    mini = LONG_MAX;
   
    for(int i=0;i<n;i++)
    {
        maxi = max(diff[i],maxi);
        mini = min(diff[i], mini);
    }
    long ans2 = maxi - mini;
    ans1= max(ans1,ans2);
  cout<<ans1<<endl;
    return 0;
}

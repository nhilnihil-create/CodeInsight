#include<bits/stdc++.h>
using namespace std;
map<double,int>mp;
int main()


{
    int a,b,c=0,t,i,j,k;
    string s1,s2;
    cin>>t;
    int ara[t];
    for(i=0;i<t;i++)
    {
        cin>>ara[i];
    }
    sort(ara,ara+t);
    for(i=0;i<t;i++)
    {
       for(j=0;j<i;j++)
       {
           for(k=0;k<j;k++)
           {
               if(ara[i]!=ara[j]&&ara[k]!=ara[i]&&ara[k]!=ara[j])
                {
                 if(ara[i]+ara[j]>ara[k]&&ara[i]+ara[k]>ara[j]&&ara[j]+ara[k]>ara[i])
                    c++;
                }
           }
       }
    }
    cout<<c<<"\n";




return 0;
}

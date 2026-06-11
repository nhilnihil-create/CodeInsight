#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n;
   cin>>n;
   string s[n];
   int t[n];
   int sum=0;
   for(int i=0;i<n;i++)
   {
       cin>>s[i]>>t[i];
       sum=sum+t[i];
   }
    string ss;
    cin>>ss;
    int tt=0;
    for(int i=0;i<n;i++)
    {
        if(ss==s[i])
        {
            sum=sum-t[i];
            tt=1;
        }
        if(tt==0)
        {
            sum=sum-t[i];
        }

    }
    cout<<sum<<endl;
}

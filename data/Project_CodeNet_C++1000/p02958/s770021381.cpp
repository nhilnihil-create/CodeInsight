#include <bits/stdc++.h>
#include "iostream"

using namespace std;
int main()
{  //freopen("D:\\input.txt","r",stdin);
    int n,c=0,o=0;
    cin>>n;
    int p[1000],pp[1000];
    for(int i=0;i<n;i++)
        {cin>>p[i];
        pp[i]=p[i];
        }
    sort(p,p+n);

    for(int i=0;i<n;i++)
    {
        if(p[i]==pp[i])
           {
           o++;
           continue;
           }
         for(int j=0;j<n;j++)
        {
           // cout<<p[i]<<pp[i]<<c<<o<<endl;
         if(p[i]==pp[j] && p[j]==pp[i])
            {c++;

        }
      }
    }

            if(c<=2 && o>=n-2)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;

}

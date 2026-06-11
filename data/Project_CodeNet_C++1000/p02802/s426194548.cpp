#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,p=0,q=0,i,n,k;
    cin>>n>>m;
    int a[m+2];
    int b[n+3]= {0};
    string s[m+2];
    for(i=0; i<m; i++)
    {
        cin>>a[i]>>s[i];
    }
    for(i=0; i<m; i++)
    {
        if(s[i]=="WA")
        {
            if(b[a[i]]>=0)
            {
                b[a[i]]++;
            }

        }
        else
        {
            if(b[a[i]]>=0)
            {
                p++;
                q=q+b[a[i]];
                b[a[i]]=-1;
            }
        }
      //  cout<<b[a[i]]<<endl;

    }
    cout<<p<<" "<<q<<endl;

}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,k,l,c=0;
    cin>>n>>m;
    int ar[m+10];
    string s[m+10];
    for(i=0; i<m; i++)
    {
        cin>>ar[i]>>s[i];
    }
    int br[n+10]= {0};

    l=0;
    for(i=0; i<m; i++)
    {
        if(s[i]=="WA")
        {
            if(br[ar[i]]>=0)
            {
                br[ar[i]]++;

            }
        }
        else
        {
            if(br[ar[i]]>=0)
            {
                c++;
                l=l+br[ar[i]];
//                cout<<l<<endl;
                br[ar[i]]=-1;
            }
        }
    }
    cout<<c<<" "<<l<<endl;
}

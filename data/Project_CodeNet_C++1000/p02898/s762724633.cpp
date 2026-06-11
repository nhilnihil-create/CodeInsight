#include<bits/stdc++.h>
using namespace std;

int main()
{
        int a,b,f=0,j,k,sum,ans,n,odd,even,c=0;
    
        cin>>a>>b;
        for(int i=0;i<a;i++)
        {
            cin>>k;
            if(k>=b)
                c++;
        }
        cout<<c<<"\n";
        return 0;
    }

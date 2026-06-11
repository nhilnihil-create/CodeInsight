#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m,flag=0,i;
    cin>>n;
    for(i=9;i>0;i--)
    {
        if(n%i==0)
        {
            m=n/i;
            if(m>=1&&m<=9)
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}


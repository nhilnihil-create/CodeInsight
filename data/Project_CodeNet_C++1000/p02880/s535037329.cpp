#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long m,n,i,j,k,x,y,z,a[100000],p=-10,q=1000000,cnt=0;
    cin>>n;
    for(i=1;i<=9;i++)
    {
        if(n%i==0)
        {
            p=i;
            q=n/i;
            if(q<=9)
            {
                cnt=1;
                break;
            }
        }
    }
    if(cnt==1)
    {
        cout<<"Yes"<<endl;

    }

    else
        cout<<"No"<<endl;

}


#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i,j,a,b;
    cin>>n;
    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        {
            if(i*j==n)
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}

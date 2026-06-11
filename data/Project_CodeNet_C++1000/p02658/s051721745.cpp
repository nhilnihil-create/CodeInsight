#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,i,multi=1,k=0;
    cin>>n;
    long long int x[n];
    for(i=0;i<n;i++)
    {
        cin>>x[i];
        if(x[i]==0)
        {
            cout<<0<<endl;
            return 0;
        }
    }
    for(i=0;i<n;i++)
    {
        multi*=x[i];
        k=1000000000000000000/multi;
        if(i+1<n&&x[i+1]>k)
        {
            cout<<-1<<endl;
            return 0;
        }
    }

        cout<<multi<<endl;
    return 0;
}

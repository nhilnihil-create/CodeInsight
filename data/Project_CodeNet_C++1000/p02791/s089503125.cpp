#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int N,i,mini,c=1;
    cin>>N;
    long long int a[N];
    for(i=0;i<N;i++)
    {
        cin>>a[i];
    }
    mini=a[0];
    for(i=1;i<N;i++)
    {
        if(mini>a[i])
        {
            c++;
            mini=a[i];
        }
    }
    cout<<c<<endl;
}

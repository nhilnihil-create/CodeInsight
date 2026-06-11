#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long int a,b,n,m;
    int i,c=0,d=0;
    cin>>a>>b;
    n=min(a,b);
    m=max(a,b);
    for (i=n+1;i<m;i++)
    {
        if (abs(a-i)==abs(b-i))
        {
            cout<<i<<endl;
            return 0;
        }
    }

    cout<<"IMPOSSIBLE"<<endl;



}

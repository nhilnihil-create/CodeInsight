#include<iostream>
using namespace std;
int main()
{
    long long n,i,mi,c=1;
    cin>>n;
    long long m[n];
    for(i=0;i<n;i++)
    {
        cin>>m[i];
    }
    mi=m[0];
    for(i=1;i<n;i++)
    {
        if(mi>=m[i])
        {
            c++;
        }
        mi=min(mi,m[i]);
    }
    cout<<c<<endl;
    return 0;
}

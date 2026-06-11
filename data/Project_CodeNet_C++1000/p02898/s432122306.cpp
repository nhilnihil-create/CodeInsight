#include<iostream>
using namespace std;
int main()
{
    int i,n,k,c=0,l;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>l;
        if(l>=k)
        {
            c++;
        }
    }
    cout<<c<<"\n";
    return 0;
}

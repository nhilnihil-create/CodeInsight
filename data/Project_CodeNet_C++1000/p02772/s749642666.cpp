#include<iostream>
using namespace std;
int main()
{
    long long n,i,a[200],f=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]%2==0)
        {
            if(a[i]%3!=0&&a[i]%5!=0)
            {
                f++;
            }
        }
    }
    if(f>0)
    {
        cout<<"DENIED"<<endl;
    }
    else
    {
        cout<<"APPROVED"<<endl;
    }
    return 0;
}
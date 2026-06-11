#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int s,t=0;
    if(n%2==0)
    {
    s=n/2;
    for(int i=s;i<n;i++)
    {
        if(a[i-s]==a[i])
        {
            t++;
        }

    }
    if(t==s)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}

#include<iostream>
using namespace std;
int main()
{
    int k=500,x,sum=0,n,i;
    cin>>n>>x;
    for(i=0;i<n;i++)
    {
        sum=sum+k;
    }

    if(sum>=x)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
 return 0;
}

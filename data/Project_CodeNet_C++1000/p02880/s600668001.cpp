#include<iostream>
using namespace std;
int main()
{
    int n,s,t=0;
    cin>>n;
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            s=i*j;
           if(s==n)
           {
              t=1;
              break;
           }

        }
    }

    if(t==1)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    return 0;
}

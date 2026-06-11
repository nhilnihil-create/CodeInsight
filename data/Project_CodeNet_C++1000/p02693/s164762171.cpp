#include<iostream>
using namespace std;
int main()
{
    long long n,a,b,i,s=0;
    cin>>n;
    cin>>a>>b;
    for(i=a;i<=b;i++)
    {
        if(i%n==0)
        {
            s++;
            break;
        }
    }
    if(s==0)
    {
        cout<<"NG"<<endl;
    }
    else
    {
        cout<<"OK"<<endl;
    }
    return 0;
}
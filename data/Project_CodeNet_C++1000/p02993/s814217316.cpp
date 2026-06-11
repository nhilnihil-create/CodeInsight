#include <iostream>

using namespace std;
int a[5];
int main()
{
    int s,res=0;
    cin>>s;
    for(int i=0; i<4; i++)
    {
        a[i]=s%10;
        s=s/10;
    }
    for(int i=0; i<4; i++)
    {
        if(a[i]==a[i+1])
        {
            res++;
        }
        if(i==2)
        {
            break;
        }
    }
    if(res!=0)
    {
        cout<<"Bad";
    }
    else
    {
        cout<<"Good";
    }
}
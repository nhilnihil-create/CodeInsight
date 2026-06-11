#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,i;
    cin>>a>>b>>c>>d;
    for(i=1;i>=1;i++)
    {
        if(i%2!=0)
        {
            c-=b;
        }
        else
        {
            a-=d;
        }
        if(c<=0||a<=0)
        {
            if(i%2!=0)
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
            break;
        }
    }
    return 0;
}
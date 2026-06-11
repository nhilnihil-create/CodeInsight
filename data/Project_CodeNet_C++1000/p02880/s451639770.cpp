#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,flag=0,a=0,b=0;
    cin>>n;
    flag=0;
    for(int i=1; i<10; i++)
    {
        if(n%i==0)
        {
            a=n/i;
            b=i;

            if((a>=1&&a<=9)&&(b>=1&&b<=9))
            {
                cout<<"Yes"<<endl;
                flag=1;
                break;

            }
        }
        else continue;
    }
    if(flag==0) cout<<"No"<<endl;

}

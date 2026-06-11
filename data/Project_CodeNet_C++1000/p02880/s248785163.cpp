#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i=9,x,t=0;
    cin>>x;
    while(1)
    {
        if(x%i==0 && (x/i)<=9 && 1<=(x/i))
        {
            cout<<"Yes"<<endl;
            t=0;
            break;
        }
        else
            t=1;
        i--;
        if(i==0)
            break;

    }
    if(t==1)
        cout<<"No"<<endl;
}


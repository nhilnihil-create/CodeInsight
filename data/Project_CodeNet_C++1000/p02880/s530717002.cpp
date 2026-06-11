#include<bits/stdc++.h>
using namespace std;
int main()
{
    int X,s=0,i,j;
    bool t=0;

    cin>>X;
    for( i=1; i<10; i++)
    {
        for(j=1; j<10; j++)
        {
            s=i*j;
            if(X==s)
            {
                t=1;
            }
        }


    }

    if(t==true)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }



    return 0;
}